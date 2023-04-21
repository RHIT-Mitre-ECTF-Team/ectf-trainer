
#include "shell.h"


int car_mesg(int argc, char** argv) {
    int ctr;
    printf("Received the message:");
    for (ctr = 1; ctr < argc; ctr++) {
        printf(" %s", argv[ctr]);
    }
    printf("\n");

    if (argc > 0) {

        if (strcmp(argv[1], "PING_REPLY") == 0) {
            printf("Got a ping reply.\n");
        }
        else {
            printf("Didn't know how to handle %s\n", argv[1]);
        }

    }
    return 0;
}

// ADD_CMD(keyword, description, function name);
ADD_CMD(CAR_MESG, "Processes a message from the car", car_mesg);
