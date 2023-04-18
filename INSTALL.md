## Instructions for adding ectf-trainer to Windows.

1. Install Windows Subsystem for Linux (wsl) from a command prompt or PowerShell instance with ```wsl --install``` 
2. Not required but nice... install ```Windows Terminal```, again from the Microsoft Store.
3. Installing wsl should also install an instance of Ubuntu. To start it, find it on the Start Menu or through Windows Terminal (if you installed it).
4. At the Linux command prompt, type ```code``` to install VS Code. After it installs, you can close it.
5. Install the emulation software, QEMU, with ```sudo apt install -y qemu-system-arm```   After typing, ```qemu-system-arm -M help``` you should see a list of machines we can emulate.
6. sudo a

Other hints:
If you wish to reboot your Linux instance without shutting down Windows, you can with:
```wsl --shutdown```

