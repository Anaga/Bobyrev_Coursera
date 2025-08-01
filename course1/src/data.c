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
 * @file data.c
 * @brief Basic data manipulation functions implementation
 *
 * This implementation file provides basic data manipulation functions
 * including integer to ASCII and ASCII to integer conversions.
 *
 * @author Alex Bobyrev
 * @date August 1 2025
 *
 */

#include "data.h"
#include <stdint.h>

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base) {
    if (ptr == NULL || base < 2 || base > 16) {
        return 0;
    }
    
    uint8_t *start = ptr;
    uint8_t is_negative = 0;
    uint32_t num;
    
    if (data < 0) {
        is_negative = 1;
        num = -data;  
    } else {
        num = data;
    }
    
    if (num == 0) {
        *ptr = '0';
        ptr++;
        *ptr = '\0';
        return 2;  // "0" + null terminator
    }
    
    while (num > 0) {
        uint32_t remainder = num % base;
        if (remainder < 10) {
            *ptr = '0' + remainder;
        } else {
            *ptr = 'A' + (remainder - 10);  // A, B, C, D, E, F для hex
        }
        ptr++;
        num /= base;
    }
    
    if (is_negative) {
        *ptr = '-';
        ptr++;
    }
    
    // Add null terminator
    *ptr = '\0';
    
    uint8_t length = ptr - start + 1;  // +1 for null terminator
    
    uint8_t *end = ptr - 1;
    while (start < end) {
        uint8_t temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
    
    return length;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base) {
    if (ptr == NULL || base < 2 || base > 16 || digits == 0) {
        return 0;
    }
    
    int32_t result = 0;
    uint8_t is_negative = 0;
    uint8_t *current = ptr;
    
    if (*current == '-') {
        is_negative = 1;
        current++;
        digits--;  // Reducing digits count for the - sign
    } else if (*current == '+') {
        current++;
        digits--;  // Reducing digits count for the + sign
    }
    
    for (uint8_t i = 0; i < digits; i++) {
        uint8_t digit_value;
        
        if (*current >= '0' && *current <= '9') {
            digit_value = *current - '0';
        } else if (*current >= 'A' && *current <= 'F') {
            digit_value = *current - 'A' + 10;
        } else if (*current >= 'a' && *current <= 'f') {
            digit_value = *current - 'a' + 10;
        } else {
            // invalid character for base conversion
            break;
        }

        if (digit_value >= base) {
            break;
        }
        
        result = result * base + digit_value;
        current++;
    }
    
    if (is_negative) {
        result = -result;
    }
    
    return result;
}