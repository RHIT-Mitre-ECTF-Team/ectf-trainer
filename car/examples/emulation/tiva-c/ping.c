
#include "shell.h"


int ping(int argc, char** argv) {
    printf("Sending a ping on UART2\n");
    printf2("PING\n");
    return 0;
}

ADD_CMD(ping, "Pings the other board", ping);
