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
                              200, 122, 150, 90,   192,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */

  /* Statistics and Printing Functions Go Here */
  print_array(test, SIZE);

  print_array(NULL, SIZE); // Test with NULL array
  print_array(test, 0);    // Test with size 0

  printf("Done\n");
  unsigned char array_min = find_minimum(test, SIZE);
  printf("Minimum: %d\n", array_min);
  
  unsigned char array_max = find_maximum(test, SIZE);
  printf("Maximum: %d\n", array_max); 

  unsigned char array_mean = find_mean(test, SIZE);
  printf("Mean: %d\n", array_mean);

  unsigned char array_median = find_median(test, SIZE);
  printf("Median: %d\n", array_median);


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

unsigned char find_maximum(unsigned char *array, unsigned int size) {
  if (array == NULL || size == 0) return 0;

  unsigned char max = array[0];
  for (unsigned int i = 1; i < size; i++) {
    if (array[i] > max) {
      max = array[i];
    }
  }
  return max;
} 

unsigned char find_minimum(unsigned char *array, unsigned int size) {
  if (array == NULL || size == 0) return 0;

  unsigned char min = array[0];
  for (unsigned int i = 1; i < size; i++) {
    if (array[i] < min) {
      min = array[i];
    }
  }
  return min;
}

unsigned char find_mean(unsigned char *array, unsigned int size) {
  if (array == NULL || size == 0) return 0;

  unsigned int sum = 0;
  for (unsigned int i = 0; i < size; i++) {
    sum += array[i];
  }
  return (unsigned char)(sum / size);
} 

unsigned char find_median(unsigned char *array, unsigned int size) {
  if (array == NULL || size == 0) return 0;

  // Will use a sort from next function
  // For simplicity, we assume the array is already sorted.
  unsigned int mid = size / 2;
  // If size is even, return the average of the two middle elements
  // If size is odd, return the middle element
  if (mid == 0) {
    return (array[mid - 1] + array[mid]) / 2;
  } else {
    return array[mid];
  }
} 
