# ectf Trainer

This is a fork of the embedded shell project from Google, https://github.com/google/esh. That project has been extended to include multiple UARTs, virtual Tiva-C boards, and the ability to link multiple boards together over UART (and eavesdrop on them!).

To install, see [INSTALL.md](https://github.com/henthornlab/ectf-trainer/blob/main/INSTALL.md)


In a terminal, ```./fob.sh``` will build the fob firmware and run it on an emulated MCU with two (virtual) UARTs. These UARTs are located as TCP ports 1234 and 1235. You will be connected automatically to the interactive UART.

The first UART allows for interaction with the device. The second UART is the messaging channel between the fob and the car, but can be used interactively during development.

To try the car, use ```./car.sh```.

Finally, to use them both, run ```./connected.sh``` which will simultaneously launch both and connect them together. You will have interactive command of the fob.



The esh project provides a (limited) printf() function that can be used, along with a few of the typical ANSI C string functions (strcmp, strlen, etc.).

To add new functions to your firmware, add a C file in the fob or car directory and make sure to include "shell.h". See ping.c for an example. Register the command using the ADD_CMD directive:

```
// ADD_CMD(command, description, function name);
ADD_CMD(ping, "Pings the other board", send_ping);
```

will cause the send_ping() function to run when the user types the word ping on the console.

To send characters to the first UART, use printf(). 
To send characters to the second UART, use printf2().
