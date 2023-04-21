#include "shell.h"

int aes(int argc, char** argv) {

    struct AES_ctx ctx;
    uint8_t key[16] = {0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7,
                     0x8, 0x9, 0xa, 0xb, 0xc, 0xd, 0xe, 0xf};

    uint8_t text[16] = "0123456789abcdef";
    AES_init_ctx(&ctx, key);
    unsigned int len;

    printf("Encrypting %s using AES\n", text);
    AES_ECB_encrypt(&ctx, text);
    printf("Encrypted is %s\n", text);

    //Let's encode it in base64 so we can send it character-by-character over UART
    char b64text[16+8];
    len = encode_base64(text, 16, b64text);
    b64text[len] = '\n';
    printf("Encrypted is %s\n", b64text);
    printf2("FOB_MESG AESB64 %s\n", b64text);

    // And if you need to decrypt it:
    AES_ECB_decrypt(&ctx, text);
    printf("Which should decrypt to %s \n", text);

    return 0;
}

// ADD_CMD(command, description, function name);
ADD_CMD(aes, "Encrypts a message using AES and sends it on UART2", aes);