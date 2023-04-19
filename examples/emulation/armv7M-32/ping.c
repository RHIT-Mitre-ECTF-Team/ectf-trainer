#include "shell.h"

int ping(int argc, char** argv) {

  printf("\nGive me a ping, Vasili. One ping only, please.\n");
  uputc("X");
  uputc("X");
  printf("\nPress ctrl + a, x to exit !\n");
  return 0;
}

ADD_CMD(ping, "Pings the other board\n\tusage: ping", ping);
