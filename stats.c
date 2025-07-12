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
 * @file stats.c 
 * @brief Impl file for statistics functions
 * 
 * This file contains the implementation of functions to calculate and print
 * statistics such as minimum, maximum, mean, and median from an array of
 * unsigned char values.
 * 
 * This file is part of a course project for learning embedded software
 * development.
 *
 * @author Aleksandr Bobyrev
 * @date 12.07.2025
 *
 */

#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)
#define MAX_ELEMENTS_PER_LINE (15)

int main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */

  /* Statistics and Printing Functions Go Here */
  print_array(test, SIZE);

  print_array(NULL, SIZE); // Test with NULL array
  print_array(test, 0);    // Test with size 0

  printf("Done\n");
  return 0;
}

/* Add other Implementation File Code Here */
void print_array(unsigned char *array, unsigned int size) {
  if (array == NULL || size == 0) {
    printf("Error: Array is empty or NULL\n");
    return;
  }

  printf("Array: [");
  for(unsigned int i = 0; i < size; i++) {
    printf("%4d", array[i]);
    if (i < size - 1) {
      printf(",");
      if ((i + 1) % MAX_ELEMENTS_PER_LINE == 0) {
        printf("\n         ");
      } else {
        printf(" ");
      }
    }
  }
  printf("]\n");
}
