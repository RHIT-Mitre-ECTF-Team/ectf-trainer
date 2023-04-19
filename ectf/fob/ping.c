
#include "shell.h"


int send_ping(int argc, char** argv) {
    printf("Pinging the car.\n");
    printf2("FOB_MESG PING\n");
    return 0;
}

// ADD_CMD(command, description, function name);
ADD_CMD(ping, "Pings the other board", send_ping);
