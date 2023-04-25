
#include "shell.h"

int finish_ecdhpair(int argc, char** argv);
int car_mesg(int argc, char** argv);

int car_mesg(int argc, char** argv) {
    int ctr;
    printf("Received a message from the car:");
    for (ctr = 1; ctr < argc; ctr++) {
        printf(" %s", argv[ctr]);
    }
    printf("\n");

    
    if (argc > 1) {

        if (strcmp(argv[1], "PING_REPLY") == 0) {
            printf("Got a ping reply.\n");
        }
        else if (strcmp(argv[1], "PAIRECDH2") == 0) {
            finish_ecdhpair(argc, argv);
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
ADD_CMD(CAR_MESG, "Processes messages from the car", car_mesg);



int finish_ecdhpair(int argc, char** argv) {

    if (argc == 4) {
        uint8_t carpubkey[ECC_PUB_KEY_SIZE];
        // Now generate sharedsecret
        decode_base64((uint8_t *)argv[3], 64, carpubkey);
        ecdh_shared_secret(ECDH_privkey, carpubkey, ECDH_shared);

        // SHA-256 the sharedsecret into an AES key
        SHA256_CTX shactx;
        sha256_init(&shactx);
	    sha256_update(&shactx, ECDH_shared, ECC_PUB_KEY_SIZE);
	    sha256_final(&shactx, ECDH_AESkey);

        // Reinitialize AES with new key
        AES_init_ctx(&ctx, ECDH_AESkey);

    }
    else printf("Incorrect number of arguments for PAIRECDH2\n");
    return 0;
}