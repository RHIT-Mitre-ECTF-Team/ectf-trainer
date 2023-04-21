#include "shell.h"
#define MAX64LENGTH 100

int encode64(int argc, char** argv) {

    

    if (argc > 1) {

        unsigned char encoded[MAX64LENGTH];
        int len;

        len = strlen(argv[1]);

        if (len < MAX64LENGTH) {
            len = encode_base64(argv[1], len, encoded);
            printf("Encoded %s as %s with %d characters\n", argv[1], encoded, len);
        }
        else {
            printf("String exceeds max length of %d characters", MAX64LENGTH);
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

        if (len < MAX64LENGTH-1) {
                
                char plaintext[MAX64LENGTH];

                printf("encoded string is %d characters\n", len);
                len = decode_base64(argv[1], len, plaintext);
                printf("decoded string is %d characters\n", len);
                printf("Adding NULL at the end of decoded string\n");
                plaintext[len] = '\n';

                printf("Decoded %s as: %s\n", argv[1], plaintext);

        }
        else {
            printf("String exceeds max length of %d characters", MAX64LENGTH);
        }
    
    }
    else {
        printf("Usage is 'decode64 string'\n");
    }
        
    return 0;
}

// ADD_CMD(command, description, function name);
ADD_CMD(encode64, "Base64 encodes a string and sends it on UART2", encode64);
ADD_CMD(decode64, "Base64 decodes a string and sends it on UART2", decode64);