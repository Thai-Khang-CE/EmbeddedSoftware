# MSP432P401R Embedded Systems - Course 1 Module 2 Assessment

## Overview
This project is the final assessment for **Coursera/University of Colorado Embedded Systems - Shape the World** Course 1, Module 2. It implements and tests custom C library functions for data conversion (itoa/atoi), memory manipulation (memmove, memcpy, memset, memzero, reverse), and statistics on a **Texas Instruments MSP432P401R** microcontroller (ARM Cortex-M4F).

The code supports:
- **Host platform** (Linux/macOS/Windows with gcc): For simulation and testing without hardware.
- **MSP432 platform** (bare-metal ARM): For deployment on the MSP432P401R LaunchPad.

Key features:
- Conditional compilation for `COURSE1` (enables assessment tests in `main.c`).
- `VERBOSE` flag for debug output.
- Tests validate all functions against expected outputs.

## Copyright
```
Copyright (C) 2017 by Alex Fosdick - University of Colorado

Redistribution, modification or use of this software in source or binary
forms is permitted as long as the files maintain this copyright. Users are 
permitted to modify this and use it to learn about the field of embedded
software. Alex Fosdick and the University of Colorado are not liable for any
misuse of this material.
```

## Project Structure
```
.
├── Makefile              # Build system (gcc or arm-none-eabi-gcc)
├── sources.mk            # Source files and include paths (MSP432/HOST)
├── msp432p401r.lds       # ARM linker script
├── README.md             # This file
├── include/
│   ├── common/           # Platform-agnostic headers: course1.h, data.h, memory.h, stats.h
│   ├── CMSIS/            # ARM Cortex-M CMSIS core
│   └── msp432/           # MSP432 peripherals and system headers
└── src/
    ├── main.c            # Entry point: calls course1() tests
    ├── course1.c         # Test runners for data/memory functions
    ├── data.c            # my_itoa(), my_atoi() implementations
    ├── memory.c          # memmove(), memcpy(), memset(), memzero(), reverse()
    ├── stats.c           # Statistics functions (min/max/avg)
    ├── interrupts_msp432p401r_gcc.c  # MSP432 interrupt vectors (MSP432 only)
    ├── startup_msp432p401r_gcc.c     # MSP432 startup code (MSP432 only)
    └── system_msp432p401r.c          # MSP432 system init (MSP432 only)
```

## Prerequisites
- **Host**: GCC (standard on Linux/macOS; MinGW/MSYS2 on Windows).
- **MSP432**:
  - [ARM GCC Toolchain](https://developer.arm.com/downloads/-/gnu-rm) (arm-none-eabi-gcc).
  - MSP432P401R LaunchPad (for flashing/debugging).
  - OpenOCD or TI Code Composer Studio for flashing (not included in Makefile).

## Build Instructions
```bash
# Host platform (simulation)
make clean
make build PLATFORM=HOST COURSE1=1 VERBOSE=1

# MSP432 platform (bare-metal ELF)
make clean
make build PLATFORM=MSP432 COURSE1=1 VERBOSE=1
```

- Outputs: `main.elf` (MSP432), `main.map` (memory map).
- `.o`, `.d`, `.i`, `.asm` files generated in `src/`.
- Use `compile-all` target for objects only.

## Run/Flash
### Host
```bash
./main.elf
```
Expected output: Pass/fail results for 8 tests (data1/2, memmove1-3, memcopy, memset, reverse).

### MSP432
1. Flash ELF: Use OpenOCD or `arm-none-eabi-gdb`:
   ```
   openocd -f interface/ti-icdi.cfg -f target/msp432p401r.cfg -c 'program main.elf verify reset exit'
   ```
2. Debug with gdb:
   ```
   arm-none-eabi-gdb main.elf
   (gdb) target remote localhost:3333
   (gdb) load
   (gdb) continue
   ```
Connect via UART (115200 baud) for printf output.

## Modules & Tests
- **course1()**: Runs 8 tests:
  | Test | Functions Tested |
  |------|------------------|
  | test_data1/2 | my_itoa/my_atoi (hex/dec) |
  | test_memmove1-3 | memmove (non-overlap/overlap) |
  | test_memcopy | my_memcopy |
  | test_memset | my_memset/my_memzero |
  | test_reverse | my_reverse |

- **data.h**: Base conversion.
- **memory.h**: Memory ops (handles overlap).
- **stats.h**: Data set stats (min/max/avg).

All tests print `PASS` or `FAIL` with verbose details.

## Troubleshooting
- Missing ARM toolchain? Install via `apt install gcc-arm-none-eabi` (Linux).
- Linker errors? Verify `msp432p401r.lds`.
- No output on MSP432? Check UART pins (P1.2/3), baud rate.
- Clean rebuild: `make clean build`.

## Assessment Goals
Implement `data.c` and `memory.c` to pass all tests on both platforms. `stats.c` included for completeness.

Fork, modify, and submit as needed for course requirements.

