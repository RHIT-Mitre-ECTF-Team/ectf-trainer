# ectf Trainer

This is a fork of the embedded shell project from Google, https://github.com/google/esh. That project has been extended to include multiple UARTs, virtual Tiva-C boards, and the ability to link multiple boards together over UART.

To install, see INSTALL.md.

After installation, head to the ectf directory where you will find virtual examples of the car and the fob.

Since most of the interactive behavior is controlled by the fob, ```cd fob```.

In a terminal, ```make run``` will build the fob firmware and run it on an emulated MCU with two (virtual) UARTs. These UARTs are located as TCP ports 1234 and 1235.

The first UART allows for interaction with the device. The second UART is the messaging channel between the fob and the car, but can be used interactively during development.

To access the first UART, ```nc localhost 1234``` on the VM.

The second UART can be connected to a board or worked with interactively using ```nc localhost 1235```.

The esh project provides a (limited) printf() function that can be used, along with a few of the typical ANSI C string functions (strcmp, strlen, etc.).

To add new functions to your firmware, add a C file in the fob or car directory and make sure to include "shell.h". See ping.c for an example. Register the command using the ADD_CMD directive:

```
// ADD_CMD(command keyword, description, function name);
ADD_CMD(ping, "Pings the other board", send_ping);
```

will cause the send_ping() function to run when the user types the word ping on the console.

To send text to UART1, use printf(). 
To send text to UART2, use printf2().

