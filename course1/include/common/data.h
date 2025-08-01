/******************************************************************************
 * Copyright (C) 2025 by Alex Bobyrev 
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. 
 *
 *****************************************************************************/
/**
 * @file data.h
 * @brief Basic data manipulation functions
 *
 * This header file provides function declarations for basic data manipulation
 * including integer to ASCII and ASCII to integer conversions.
 *
 * @author Alex Bobyrev
 * @date August 1 2025
 *
 */
#ifndef __DATA_H__
#define __DATA_H__

#include <stdint.h>
#include <stddef.h>

/**
 * @brief Integer-to-ASCII conversion
 *
 * Converts data from a standard integer type into an ASCII string.
 * All operations are performed using pointer arithmetic, not array indexing.
 * Supports bases 2 to 16. Handles signed data.
 *
 * @param data The signed 32-bit integer to convert
 * @param ptr Pointer to store the converted character string
 * @param base The base to convert to (2-16)
 *
 * @return Length of the converted data (including null terminator)
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief ASCII-to-Integer conversion
 *
 * Converts data back from an ASCII represented string into an integer type.
 * All operations are performed using pointer arithmetic, not array indexing.
 * Supports bases 2 to 16. Handles signed data.
 *
 * @param ptr Pointer to the character string to convert
 * @param digits Number of digits in the character set
 * @param base The base to convert from (2-16)
 *
 * @return The converted 32-bit signed integer
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */