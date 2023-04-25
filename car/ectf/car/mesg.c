
#include "shell.h"

int attempt_simplepair(int argc, char** argv);
int attempt_ecdhpair(int argc, char** argv);

int fob_mesg(int argc, char** argv) {
    int ctr;
    printf("Received a message from the fob:");
    for (ctr = 1; ctr < argc; ctr++) {
        printf(" %s", argv[ctr]);
    }
    printf("\n");

    if (argc > 1) {

        if (strcmp(argv[1], "PING") == 0) {
            printf("Got a ping.\n");
            printf2("CAR_MESG PING_REPLY\n");
        }
        else if (strcmp(argv[1], "PAIR") == 0) {
            attempt_simplepair(argc, argv);
        }
        else if (strcmp(argv[1], "PAIRECDH") == 0) {
            attempt_ecdhpair(argc, argv);
        }
        else if (strcmp(argv[1], "AESB64") == 0) {
            if (argc == 3) { 
                uint8_t decoded[100];
                int len;
                len = decode_base64((uint8_t *) argv[2], strlen(argv[2]), decoded);
                AES_ECB_decrypt(&ctx, decoded);
                decoded[len] = '\0';
                printf("Decoded/decrypted as %s\n", decoded);
            }
            else {
                printf("Missing AESB64 encoded message\n");
            }
        }
        else if (strcmp(argv[1], "B64") == 0) {
            if (argc == 3) { 
                printf("Decoding Base64\n");
                uint8_t decoded[100];
                int len;
                len = decode_base64((uint8_t *) argv[2], strlen(argv[2]), decoded);
                decoded[len] = '\0';
                printf("Decoded as %s", decoded);
            }
            else {
                printf("Missing Base64 encoded message\n");
            }
        }
        else {
            printf("Didn't know how to handle %s\n", argv[1]);
        }

    }
    return 0;
}

// ADD_CMD(keyword, description, function name);
ADD_CMD(FOB_MESG, "Processes messages from the fob", fob_mesg);

int attempt_simplepair(int argc, char** argv) {

    printf("Attempting a simple PAIR\n");
    if (argc == 4) {
  
        if (atoi(argv[3]) == pairing_PIN)
        {
            printf("Paired with fob %s\n", argv[2]);
        }
        else printf("Pairing with fob %s failed.\n", argv[2]);

    }
    else printf("Received incorrect number of PAIR arguments from fob\n");
    return 0;
}

int attempt_ecdhpair(int argc, char** argv) {

    printf("Attempting an ECDH pair\n");
    if (argc == 5) {

        if (atoi(argv[3]) == pairing_PIN) {
            uint8_t pubkey_b64[65];
            uint8_t fobpubkey[ECC_PUB_KEY_SIZE];
            printf("Starting EC Diffie-Hellman key exchange.\n");

            decode_base64(ECDH_privkey_b64, 32, ECDH_privkey);
            ecdh_generate_keys(ECDH_pubkey, ECDH_privkey);
            encode_base64(ECDH_pubkey, ECC_PUB_KEY_SIZE, pubkey_b64);
            printf2("CAR_MESG PAIRECDH2 %d %s\n", car_ID, pubkey_b64);

            // Now generate sharedsecret
            decode_base64((uint8_t *)argv[4], 64, fobpubkey);
            ecdh_shared_secret(ECDH_privkey, fobpubkey, ECDH_shared);

            // SHA-256 the sharedsecret into an AES key
            SHA256_CTX shactx;
            sha256_init(&shactx);
	        sha256_update(&shactx, ECDH_shared, ECC_PUB_KEY_SIZE);
	        sha256_final(&shactx, ECDH_AESkey);

            // Reinitialize AES with new key
            AES_init_ctx(&ctx, ECDH_AESkey);

        }
        else printf("Incorrect PIN for pairing\n");

    }
    else printf("Received incorrect number of pairing arguments from fob\n");
    return 0;
}