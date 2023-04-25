#
# Copyright 2022 Google LLC
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     https://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

TOOLCHAIN_PREFIX ?= arm-none-eabi-
OPTIMIZATION = g

STARTUP = start

DEFINES = -mcpu=cortex-m4 -mthumb -mtune=cortex-m4
DEFINES += -DSHELL_NO_PRINTF_LL

ASM_FLAGS = -march=armv7e-m

ROM_BASE_PHYSICAL = 0x00000000
ROM_SIZE = 0x00040000

RAM_BASE_PHYSICAL = 0x20000000
RAM_SIZE = 0x00008000

# MANDATORY:
#     Provide relative path to shell/ from current directory
#     Only Variable should be set above this line

# MANDATORY:
#     Provide relative path to shell/ from current directory
#     Only Variable should be set above this line
SHELL_ROOT=../../shell
-include $(SHELL_ROOT)/Makefile
# ^^ Do not move the above line. All user targets to be defined below this line!

# ------------------------ User targets below this line ------------------------
### run: Launches QEMU and loads the project binary on it
run: $(PROJECT).elf
	@echo "Connect to the car using: nc localhost 1236"
	@echo "Monitor car-fob communication using: nc localhost 1237"
	@qemu-system-arm -M lm3s6965evb -cpu cortex-m3 -nographic \
		-kernel $(PROJECT).elf -serial tcp::1236,server,nowait \
		-serial tcp::1237,server,nowait

connected: $(PROJECT).elf
	@echo "Connect to the car using: nc localhost 1236"
	@echo "The car is listening on 1237"
	@qemu-system-arm -M lm3s6965evb -cpu cortex-m3 -nographic \
		-kernel $(PROJECT).elf -serial tcp::1236,server,nowait \
		-serial udp::4555@:4556

### debug: Qemu with GDB server. To be executed before 'make gdb'
debug:
	@echo Please use \"make gdb\" in another terminal to attach gdb.
	@echo Use \"cltr+a,x\" to quit qemu debug
	@qemu-system-arm -S -M lm3s811evb -cpu cortex-m3 -nographic -kernel \
        $(PROJECT).elf -gdb tcp::1234

### gdb: Launches GDB and connects to qemu. To be executed after 'make debug'
gdb:
	@gdb-multiarch $(PROJECT).elf -ex "target remote localhost:1234"`


