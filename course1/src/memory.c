/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */

#include "memory.h"
#include <stdint.h>

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length) {
    if (src == NULL || dst == NULL || length == 0) {
        return dst;
    }

    if (src == dst) { 
        return dst;
    }
    
    if (dst <src || dst >= (src + length)) {
        uint8_t *temp_src = src;
        uint8_t *temp_dst = dst;
        for (size_t i = 0; i < length; i++) {
            *temp_dst = *temp_src;
            temp_dst++;
            temp_src++;
        }
    } else {
        // Overlaping areas
        // Copying from end to start to avoid overwriting source data
        // This is necessary when destination starts in the source range
        uint8_t *temp_src = src + length - 1;
        uint8_t *temp_dst = dst + length - 1;
        for (size_t i = 0; i < length; i++) {
            *temp_dst = *temp_src;
            temp_dst--;
            temp_src--;
        }
    }
    
    return dst;
}
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length) {
    if (src == NULL || dst == NULL || length == 0) {
        return dst;
    }

    if (src == dst) { 
        return dst;
    }

    uint8_t *temp_src = src;
    uint8_t *temp_dst = dst;
    
    for (size_t i = 0; i < length; i++) {
        *temp_dst = *temp_src;
        temp_dst++;
        temp_src++;
    }
    
    return dst;
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value) {
  // No operation needed for zero length or null pointer src
    if (src == NULL || length == 0) { 
        return src;
    }
    
    // Set all bytes in the memory to the specified value
    // Using pointer arithmetic to set each byte
    uint8_t *temp_src = src;
    
    for (size_t i = 0; i < length; i++) {
        *temp_src = value;
        temp_src++;
    }
    
    return src;
}

uint8_t * my_memzero(uint8_t * src, size_t length) {
    if (src == NULL || length == 0) {
        return src;
    }
    
    uint8_t *temp_src = src;
    
    for (size_t i = 0; i < length; i++) {
        *temp_src = 0;
        temp_src++;
    }
    
    return src;
}

uint8_t * my_reverse(uint8_t * src, size_t length) {
    if (src == NULL || length <= 1) {
        return src;
    }
    
    uint8_t *start = src;
    uint8_t *end = src + length - 1;
    
    // Меняем местами элементы с начала и конца, двигаясь к центру
    while (start < end) {
        uint8_t temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
    
    return src;
}

int32_t * reserve_words(size_t length) {
    if (length == 0) {
        return NULL;
    }
    
    // Выделяем память для length слов (каждое слово - int32_t)
    int32_t *ptr = (int32_t *)malloc(length * sizeof(int32_t));
    
    return ptr;  // malloc возвращает NULL при неудаче
}

void free_words(void * src) {
    if (src != NULL) {
        free(src);
    }
}