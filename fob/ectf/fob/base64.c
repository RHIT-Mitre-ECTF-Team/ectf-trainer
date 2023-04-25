#include "shell.h"

// Base64 encoded strings are longer than byte arrays. 
// Your max length should be 4*ceil(n/3) where n is the length of
// the array to be encoded. e.g. 100 bytes are encoded in 128 characters
#define MAXARRAYLEN 100 
#define MAXBASE64LEN 128

int encode64(int argc, char** argv) {

    if (argc > 1) {

        uint8_t encoded[MAXBASE64LEN];
        int len;

        len = strlen(argv[1]);
        if (len < MAXARRAYLEN) {
            len = encode_base64((uint8_t *) argv[1], len, encoded);
            printf("Encoded %s as %s with %d characters\n", argv[1], encoded, len);
        }
        else {
            printf("String exceeds max length of %d characters", MAXARRAYLEN);
        }
    }
    else {
        printf("Usage is 'encode64 string'\n");
    }
        
    return 0;
}

int decode64(int argc, char** argv) {

    if (argc > 1) {

        int len = strlen(argv[1]);

        if (len < MAXBASE64LEN) {
                
                uint8_t plaintext[MAXARRAYLEN + 1];
                len = decode_base64((uint8_t *) argv[1], len, plaintext);
                plaintext[len] = '\0';
                printf("Decoded %s as: %s\n", argv[1], plaintext);
        }
        else {
            printf("String exceeds max base64 string length of %d characters", MAXBASE64LEN);
        }   
    }
    else {
        printf("Usage is 'decode64 string'\n");
    }
        
    return 0;
}

// ADD_CMD(command, description, function name);
ADD_CMD(encode64, "Base64 encodes a string", encode64);
ADD_CMD(decode64, "Base64 decodes a string", decode64);