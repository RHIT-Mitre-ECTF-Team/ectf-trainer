
#include "shell.h"

int pair1(int argc, char** argv) {
    printf("Sending a pair request.\n");
    printf2("FOB_MESG PAIR %d %d\n", car_ID, pairing_PIN);
    return 0;
}

int pairchall(int argc, char** argv) {
   
    printf("Sending a pair request with challenge/response.\n");
    printf2("FOB_MESG PAIRCR %d %d\n", car_ID, pairing_PIN);

    return 0;
}

int pairecdh(int argc, char** argv) {
    
    uint8_t pubkey_b64[65];
    
    printf("Starting EC Diffie-Hellman key exchange.\n");

    decode_base64(ECDH_privkey_b64, 32, ECDH_privkey);
    ecdh_generate_keys(ECDH_pubkey, ECDH_privkey);
    encode_base64(ECDH_pubkey, ECC_PUB_KEY_SIZE, pubkey_b64);
    pubkey_b64[64] = '\0';
    printf2("FOB_MESG PAIRECDH %d %d %s\n", car_ID, pairing_PIN, pubkey_b64);
    return 0;
}

// ADD_CMD(keyword, description, function name);
ADD_CMD(pair3, "Pairs using EC Diffie-Hellman key exchange.", pairecdh);
ADD_CMD(pair2, "Pairs using challenge response", pairchall);
ADD_CMD(pair1, "Easy pairing with a car.", pair1);

