
#include "shell.h"


int ping(int argc, char** argv) {
    printf("CARMESG Received a ping\n");
    return 0;
}

ADD_CMD(PING, "Pings the other board", ping);
