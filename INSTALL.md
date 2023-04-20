## Instructions for adding ectf-trainer.

The embedded Arm / Shell toolchain really works best under Linux. I recommend a Linux VM or using WSL (instructions below). If you wish to try another OS, see the end of this document.


### An easy way to install this for Windows is through the use of Windows Subsystem for Linux. 
1. If you have a prebuilt WSL image, save it someplace, say Downloads.
2. If zipped, unzip it to get the ectf.tar file.
3. Open a shell and navigate to your file. Run ```wsl --import ectf . ectf.tar```
4. Once imported, run it with ```wsl -d ectf```

### To create a fresh WSL install:
1. Install Windows Subsystem for Linux (wsl) from a command prompt or PowerShell instance with ```wsl --install``` 
2. Not required but nice... install ```Windows Terminal```, again from the Microsoft Store.
3. Installing wsl should also install an instance of Ubuntu. To start it, find it on the Start Menu or through Windows Terminal (if you installed it).
4. At the Linux command prompt, type ```code``` to install VS Code. After it installs, you can close it.
5. Install packages, including the emulation software, QEMU, with ```sudo apt install -y make qemu-system-arm```   Check this step with ```qemu-system-arm -M help``` you should see a list of machines we can emulate.
6. Follow the directions at ```https://lindevs.com/install-arm-gnu-toolchain-on-ubuntu``` to install the GNU Arm Toolchain. Be sure to check that the install completed by using ```arm-none-eabi-gcc --version```
7. Clone this repository using ```git clone https://github.com/henthornlab/ectf-trainer.git``` into your new Ubuntu.
8. Change directory into ```cd ectf-trainer``` and then ```cd ectf/fob```
9. Build the fob using ```make clean``` followed by ```make run```
10. If everything is correct, you should see an instance of QEMU running with the compiled firmware. In another terminal window, connect to the board using ```nc localhost 1234```. Try out commands like ```help``` and ```pair```.
11. You can monitor communication from one board to the other over UART2 by ```nc localhost 1235``` 

Other hints:
If you wish to reboot your Linux instance without shutting down Windows, you can with:
```wsl --shutdown```

### Other OS installation requirements.

To make this work, you will need the following:
* GNU Arm Toolchain. Check with ```arm-none-eabi-gcc --version```
* QEMU for Arm. Check with ```qemu-system-arm -M help```
* Various other tools including nc and socat.

