
#include "shell.h"


int pair(int argc, char** argv) {
    printf("Sending a pair request.\n");
    printf2("FOB_MESG PAIR\n");
    return 0;
}

// ADD_CMD(keyword, description, function name);
ADD_CMD(pair, "Starts the pairing process with a car.", pair);
