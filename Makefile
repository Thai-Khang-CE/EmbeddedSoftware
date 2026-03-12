#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

TARGET = main

# Architectures Specific Flags
LINKER_FILE = ./msp432p401r.lds
CPU = cortex-m4
ARCH = thumb
SPECS = nosys.specs

# Compiler Flags and Defines
ifeq ($(PLATFORM), MSP432)
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-gcc
	LDFLAGS = -Wl,-T,$(LINKER_FILE),-Map=$(TARGET).map
	CFLAGS = -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) -O2 -Wall -D$(PLATFORM)
else
	CC = gcc
	LD = gcc
	LDFLAGS = -Wl,-Map=$(TARGET).map
	CFLAGS = -O2 -Wall -D$(PLATFORM)
endif

ifdef VERBOSE
CFLAGS += -DVERBOSE
CPPFLAGS += -DVERBOSE
ASFLAGS += -DVERBOSE
endif

ifdef COURSE1
CFLAGS += -DCOURSE1
CPPFLAGS += -DCOURSE1
ASFLAGS += -DCOURSE1
endif

ASFLAGS += -S
CPPFLAGS += -E -D$(PLATFORM)

OBJECTS = $(SOURCES:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

%.i : %.c
	$(CC) $(CPPFLAGS) $(INCLUDES)  $< -o $@

%.asm : %.c
	$(CC) $(ASFLAGS) $(INCLUDES) -c $< -o $@

.PHONY: compile-all
compile-all: $(OBJECTS)

.PHONY: build
build: compile-all
	$(LD) $(CFLAGS) $(LDFLAGS) $(OBJECTS) -o $(TARGET).elf

.PHONY: clean
clean:
	rm -rf $(OBJECTS) $(TARGET).elf $(TARGET).map







