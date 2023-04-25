#include "shell.h"

//extern uint8_t ECDH_privkey_b64[];
//extern uint8_t ECDH_privkey[];
//extern uint8_t ECDH_pubkey[];
//extern uint8_t ECDH_shared[];
//extern uint8_t ECDH_AESkey[];
//extern uint8_t AES_key[];
//extern struct AES_ctx ctx;


int ecdh_test(int argc, char** argv) {

    uint8_t b64privkey2[32] = "wP/uwP/uwP/uwP/uwP/uwP/uwP/uwP/u";
    uint8_t privkey2[ECC_PRV_KEY_SIZE];
    uint8_t pubkey2[ECC_PUB_KEY_SIZE];
    uint8_t sharedsecret2[ECC_PRV_KEY_SIZE];
    uint8_t keytest[AES_KEYLEN];
    uint8_t b64test[45];
    int len = 0;

    printf("Testing the ecdh key exchange\n");

    decode_base64(ECDH_privkey_b64, 32, ECDH_privkey);
    decode_base64(b64privkey2, 32, privkey2);

    ecdh_generate_keys(ECDH_pubkey, ECDH_privkey);
    ecdh_generate_keys(pubkey2, privkey2);

    ecdh_shared_secret(ECDH_privkey, pubkey2, ECDH_shared);
    ecdh_shared_secret(privkey2, ECDH_pubkey, sharedsecret2);

    SHA256_CTX shactx;
    sha256_init(&shactx);
	sha256_update(&shactx, ECDH_shared, ECC_PUB_KEY_SIZE);
	sha256_final(&shactx, ECDH_AESkey);

    len = encode_base64(ECDH_AESkey, AES_KEYLEN, b64test);
    b64test[len] = '\0';

    printf("First shared key is %s\n", b64test);

    sha256_init(&shactx);
    sha256_update(&shactx, sharedsecret2, ECC_PUB_KEY_SIZE);
	sha256_final(&shactx, keytest);

    len = encode_base64(keytest, AES_KEYLEN, b64test);
    b64test[len] = '\0';
    printf("Should be same as %s\n", b64test);

    printf("Switching fob AES key to new value. Try AES tests now.\n");

    AES_init_ctx(&ctx, ECDH_AESkey);

    return 0;
}

// ADD_CMD(command, description, function name);
ADD_CMD(ecdh_test, "Tests ECDH functions", ecdh_test);
