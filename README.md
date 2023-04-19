# ectf Trainer

This is a fork of the embedded shell project from Google, https://github.com/google/esh. 

To install, see INSTALL.md.

After installation, head to the ectf directory where you will find virtual examples of the car and the fob.

Since most of the interactive behavior is controlled by the fob, ```cd fob``.

In a terminal, ```make run``` will build the fob firmware and run it on an emulated MCU with two (virtual) UARTs.

The first UART allows for interaction with the device. The second UART is the messaging channel between the fob and the car, but can be used interactively as well.

To access the first UART, ```nc localhost 1234``` on the VM.

The second UART can be connected to a board or worked with interactively using ```ns localhost 1235```.