#include "shell.h"

int aes(int argc, char** argv) {

    struct AES_ctx ctx;
    uint8_t key[16] = {0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7,
                     0x8, 0x9, 0xa, 0xb, 0xc, 0xd, 0xe, 0xf};

    uint8_t plaintext[16] = "0123456789abcdef";
    AES_init_ctx(&ctx, key);

    printf("Encrypting %s using AES\n", plaintext);
    AES_ECB_encrypt(&ctx, plaintext);

    // You can send it as a string
    printf2("FOB_MESG AES %s\n", plaintext);


    // And if you need to decrypt it:
    AES_ECB_decrypt(&ctx, plaintext);
    printf("Which should decrypt to %s \n", plaintext);


    return 0;
}

// ADD_CMD(command, description, function name);
ADD_CMD(aes, "Encrypts a message using AES and sends it on UART2", aes);