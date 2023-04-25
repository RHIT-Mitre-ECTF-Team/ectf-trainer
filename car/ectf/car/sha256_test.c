#include "shell.h"


int sha256_test(int argc, char** argv) {
    printf("Starting sha256 test\n");

    SHA256_CTX shactx;
    BYTE text1[] = {"abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq"};
    BYTE hash1[SHA256_BLOCK_SIZE] = {0x24,0x8d,0x6a,0x61,0xd2,0x06,0x38,0xb8,0xe5,0xc0,0x26,0x93,0x0c,0x3e,0x60,0x39,
	                                 0xa3,0x3c,0xe4,0x59,0x64,0xff,0x21,0x67,0xf6,0xec,0xed,0xd4,0x19,0xdb,0x06,0xc1};
    BYTE buf[SHA256_BLOCK_SIZE];

    uint8_t b64_hash1[45];
    uint8_t b64_buf[45];
    int len;

    sha256_init(&shactx);
	sha256_update(&shactx, text1, strlen((char *)text1));
	sha256_final(&shactx, buf);

    len = encode_base64(hash1, SHA256_BLOCK_SIZE, b64_hash1);
    b64_hash1[len] = '\0';

    len = encode_base64(buf, SHA256_BLOCK_SIZE, b64_buf);
    b64_buf[len] = '\0';

    printf("Base64 of SHA-256 test is %s\n", b64_buf);
    printf("Should be %s\n", b64_hash1);

    return 0;
}

// ADD_CMD(keyword, description, function name);
ADD_CMD(sha256_test, "Tests the sha256 implementation", sha256_test);