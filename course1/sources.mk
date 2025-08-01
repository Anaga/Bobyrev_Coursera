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

# Default platform if not specified
PLATFORM ?= HOST

# Platform independent source files
SOURCES = main.c \
          memory.c

# Platform-specific source files add to list:
ifeq ($(PLATFORM),MSP432)
    SOURCES += interrupts_msp432p401r_gcc.c \
               startup_msp432p401r_gcc.c \
               system_msp432p401r.c
else ifeq ($(PLATFORM),HOST)
    # No host specific source files
endif

# Add your include paths to this variable

# Platform independent include paths
INCLUDES = -I../include/common
# Platform-specific include paths
ifeq ($(PLATFORM),MSP432)
	INCLUDES += -I../include/msp432	\
                -I../include/CMSIS

else ifeq ($(PLATFORM),HOST)
	# No host specific include paths	
endif
