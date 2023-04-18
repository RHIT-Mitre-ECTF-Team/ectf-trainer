qemu-system-arm -M lm3s6965evb -cpu cortex-m3 -nographic \
		-kernel shell.elf -serial tcp::1234,server,nowait 
socat TCP4-LISTEN:3000 TCP4:1234
