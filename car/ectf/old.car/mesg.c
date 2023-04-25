
#include "shell.h"


int mesg(int argc, char** argv) {
    int ctr;
    printf("Received the message:");
    for (ctr = 1; ctr < argc; ctr++) {
        printf(" %s", argv[ctr]);
    }
    printf("\n");
    return 0;
}

// ADD_CMD(keyword, description, function name);
ADD_CMD(MESG, "Processes a message from the other board", mesg);
