/* Add Author and Project Details here */
# Course 1 Final Assessment - Embedded Systems Software

## Overview

This project is the final assessment for **Introduction to Embedded Systems Software and Development Environments** course on Coursera. It demonstrates fundamental embedded software development skills including memory manipulation, data conversion, cross-platform compilation, and build system configuration.

## Project Structure

```
course1/
├── Makefile                    # Multi-platform build system
├── sources.mk                  # Source files and include paths configuration
├── msp432p401r.lds            # Linker script for MSP432 target
├── README.md                   # This file
├── include/
│   ├── common/
│   │   ├── course1.h          # Test functions declarations
│   │   ├── data.h             # Data conversion functions
│   │   ├── memory.h           # Memory manipulation functions  
│   │   ├── platform.h         # Platform-specific definitions
│   │   └── stats.h            # Statistical analysis functions
│   ├── msp432/
│   │   ├── msp432p401r.h      # MSP432 microcontroller definitions
│   │   ├── msp_compatibility.h
│   │   └── system_msp432p401r.h
│   └── CMSIS/
│       ├── cmsis_gcc.h        # ARM CMSIS headers
│       ├── core_cm4.h
│       ├── core_cmFunc.h
│       ├── core_cmInstr.h
│       └── core_cmSimd.h
└── src/
    ├── course1.c              # Test suite implementation
    ├── data.c                 # Data conversion functions
    ├── main.c                 # Application entry point
    ├── memory.c               # Memory manipulation functions
    ├── stats.c                # Statistical analysis functions
    ├── interrupts_msp432p401r_gcc.c  # MSP432 interrupt handlers
    ├── startup_msp432p401r_gcc.c     # MSP432 startup code
    └── system_msp432p401r.c          # MSP432 system initialization
```

## Features

### Memory Manipulation Functions
- **`my_memmove()`** - Safe memory move with overlap handling
- **`my_memcopy()`** - Basic memory copy (no overlap protection)
- **`my_memset()`** - Set memory to a specific value
- **`my_memzero()`** - Zero out memory regions
- **`my_reverse()`** - Reverse byte order in memory
- **`reserve_words()`** / **`free_words()`** - Dynamic memory allocation

### Data Conversion Functions
- **`my_itoa()`** - Integer to ASCII conversion (supports bases 2-16)
- **`my_atoi()`** - ASCII to integer conversion (supports bases 2-16)

### Statistical Analysis Functions
- **`find_minimum()`** / **`find_maximum()`** - Find min/max values
- **`find_mean()`** / **`find_median()`** - Calculate mean and median
- **`sort_array()`** - Sort array in descending order
- **`print_array()`** / **`print_statistics()`** - Debug output functions

## Build System

The project uses a sophisticated Makefile supporting dual-platform compilation:

### Supported Platforms
- **HOST** - Native compilation for development and testing
- **MSP432** - Cross-compilation for MSP432 microcontroller

### Build Targets
- `build` - Build complete application
- `compile-all` - Compile all source files without linking
- `clean` - Remove all generated files
- `size` - Display executable size information
- `%.o` - Build individual object files
- `%.i` - Generate preprocessed files
- `%.asm` - Generate assembly output
- `%.d` - Generate dependency files

### Compile-Time Switches
- **`COURSE1=1`** - Enable course1 test functions
- **`VERBOSE=1`** - Enable debug output
- **`PLATFORM=MSP432`** - Target MSP432 platform (default: HOST)

## Building and Running

### Prerequisites
- **GCC** (for HOST compilation)
- **ARM GNU Toolchain** (`arm-none-eabi-gcc`) for MSP432 compilation
- **Make** build system

### Build Examples

```bash
# Build for host with verbose output and course1 tests
make build COURSE1=1 VERBOSE=1

# Build for MSP432 target
make build PLATFORM=MSP432 COURSE1=1

# Clean build artifacts
make clean

# Compile only (no linking)
make compile-all PLATFORM=MSP432

# Show executable size
make size
```

### Running Tests

```bash
# Run the complete test suite (HOST only)
./course1.out
```

### Expected Output
When run with `COURSE1=1 VERBOSE=1`, the program executes 8 comprehensive tests:

1. **Data Conversion Tests**: Hexadecimal and decimal number conversion
2. **Memory Move Tests**: Various overlap scenarios 
3. **Memory Operations**: Copy, set, zero, and reverse operations

**Example successful output:**
```
--------------------------------
Test Results:
  PASSED: 8 / 8
  FAILED: 0 / 8
--------------------------------
```

## Technical Implementation

### Key Design Principles
- **Pointer Arithmetic Only** - No array indexing used per requirements
- **Overlap-Safe Memory Operations** - Proper handling of overlapping memory regions
- **Cross-Platform Compatibility** - Conditional compilation for different targets
- **Comprehensive Error Handling** - NULL pointer checks and boundary validation

### Memory Management
- All memory operations use pointer arithmetic exclusively
- Dynamic memory allocation through `reserve_words()` / `free_words()`
- Proper handling of overlapping memory regions in `my_memmove()`

### Platform Abstraction
- `platform.h` provides platform-specific `PRINTF` macro
- Conditional compilation enables/disables debug output based on target platform
- MSP432 builds exclude standard library dependencies

## Course Integration

This project integrates concepts from all course modules:

- **Module 1**: Statistical analysis functions (`stats.c`)
- **Module 2**: Cross-platform build system (`Makefile`, `sources.mk`)
- **Module 3**: Memory layout understanding and manipulation
- **Module 4**: Complete integration and testing framework

## Development Notes

### Toolchain Versions Tested
- `gcc 9.4.0` (HOST compilation)
- `arm-none-eabi-gcc 10.3.1` (MSP432 cross-compilation)

### Known Limitations
- MSP432 target does not support printf output (embedded constraint)
- Dynamic memory allocation may be limited on actual MSP432 hardware
- Some statistical functions assume sufficient memory for temporary arrays

## Author

**Aleksandr Bobyrev**  
*Coursera Embedded Systems Course - Final Assessment*  
*August 2025*

## License

This project follows the course requirements and maintains the original copyright notice from the University of Colorado template files.