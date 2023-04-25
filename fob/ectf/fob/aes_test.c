#include "shell.h"

// AES variables set globally in shell.c
//extern struct AES_ctx ctx;
//extern uint8_t AES_key[];

int aes_test(int argc, char** argv) {
    
    uint8_t text[17] = "0123456789abcdef";
    text[16] = '\0';
    unsigned int len;

    printf("Plaintext is %s\n", text);
    AES_ECB_encrypt(&ctx, text);

    //Let's encode it in base64 so we can send it character-by-character over UART
    uint8_t b64text[25];
    len = encode_base64(text, 16, b64text);
    b64text[len] = '\0';
    printf("Encrypted/encoded is %s\n", b64text);
    printf2("FOB_MESG AESB64 %s\n", b64text);
    printf("Test the mesg handler with CAR_MESG AESB64 %s\n", b64text);

    uint8_t decoded[17];
    len = decode_base64(b64text, len, decoded);
    AES_ECB_decrypt(&ctx, decoded);
    decoded[len] = '\0';

    printf("After encrypting->encoding->decoding->decrypting we recover %s\n", decoded);
    return 0;
}

// ADD_CMD(command, description, function name);
ADD_CMD(aes_test, "Tests AES/Base64 implementation", aes_test);