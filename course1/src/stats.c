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
#include "platform.h"

/* Size of the Data Set */
#define SIZE (40)
#define MAX_ELEMENTS_PER_LINE (15)

/* Private function declaration */
// Function declarations
void get_max_min_index_and_values(unsigned char *array, unsigned int size, 
                                  unsigned int *max_index, unsigned int *min_index, 
                                  unsigned char *max_value, unsigned char *min_value);
void swap(unsigned char *a, unsigned char *b);


int stats_main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   192,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */

  /* Statistics and Printing Functions Go Here */
  print_statistics(test, SIZE);

  /* 
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

  sort_array(test, SIZE);
  printf("Sorted array: ");
  print_array(test, SIZE);

  unsigned char array_median = find_median(test, SIZE);
  printf("Median: %d\n", array_median);

  */
  return 0;
}

/* Add other Implementation File Code Here */
void print_array(unsigned char *array, unsigned int size) {
  if (array == NULL || size == 0) {
    PRINTF("Error: Array is empty or NULL\n");
    return;
  }

  PRINTF("Array: [");
  for(unsigned int i = 0; i < size; i++) {
    PRINTF("%4d", array[i]);
    if (i < size - 1) {
      PRINTF(",");
      if ((i + 1) % MAX_ELEMENTS_PER_LINE == 0) {
        PRINTF("\n        ");
      } else {
        PRINTF(" ");
      }
    }
  }
  PRINTF("]\n");

}

unsigned char find_maximum(unsigned char *array, unsigned int size) {
  if (array == NULL || size == 0) return 0;

  unsigned int max_index = 0, min_index = 0;
  unsigned char max_value = array[0], min_value = array[0];

  // Find both maximum and minimum elements in the array
  get_max_min_index_and_values(array, size, &max_index, &min_index, &max_value, &min_value);

  return max_value;
} 

unsigned char find_minimum(unsigned char *array, unsigned int size) {
  if (array == NULL || size == 0) return 0;

  unsigned int max_index = 0, min_index = 0;
  unsigned char max_value = array[0], min_value = array[0];

  // Find both maximum and minimum elements in the array
  get_max_min_index_and_values(array, size, &max_index, &min_index, &max_value, &min_value);

  return min_value;
}

unsigned char find_mean(unsigned char *array, unsigned int size) {
  if (array == NULL || size == 0) return 0;

  unsigned int sum = 0;
  for (unsigned int i = 0; i < size; i++) {
    sum += array[i];
  }
  return (unsigned char)(sum / size);
} 

void swap(unsigned char *a, unsigned char *b) {
  unsigned char temp = *a;
  *a = *b;
  *b = temp;
}


unsigned char find_median(unsigned char *array, unsigned int size) {
  if (array == NULL || size == 0) return 0;

  unsigned char ret_val = 0;

  // If size is 1, return the only element
  if (size == 1) {
    return array[0];
  }

  // Make copy of the array to sort it
  unsigned char sorted_array[size];
  for (unsigned int i = 0; i < size; i++) {
    sorted_array[i] = array[i];
  }
  // Sort the array in descending order
  sort_array(sorted_array, size);  

    
  // Will use a sort from next function
  // For simplicity, we assume the array is already sorted.
  unsigned int mid = size / 2;
  // If size is even, return the average of the two middle elements
  // If size is odd, return the middle element
  if (mid == 0) {
    ret_val = (sorted_array[mid - 1] + sorted_array[mid]) / 2;
  } else {
    ret_val = sorted_array[mid];
  }
  return ret_val;
} 


void get_max_min_index_and_values(unsigned char *array, unsigned int size, 
                                  unsigned int *max_index, unsigned int *min_index, 
                                  unsigned char *max_value, unsigned char *min_value) {

  if (array == NULL || size == 0) return;

  *max_index = 0;
  *min_index = 0;
  *max_value = array[0];
  *min_value = array[0];
  for (unsigned int i = 1; i < size; i++) {
    if (array[i] > array[*max_index]) {
      *max_index = i;
      *max_value = array[i];
    }
    if (array[i] < array[*min_index]) {
      *min_index = i;
      *min_value = array[i];
    }
  }
}

/**
 * @brief Recursive dual selection sort helper function
 *
 * Recursively sorts array in descending order by finding both maximum and minimum 
 * elements, placing max at the beginning and min at the end, then sorting the middle part.
 * This approach reduces the problem size by 2 elements per iteration.
 *
 * @param array Pointer to the array of unsigned char values.
 * @param size Size of the remaining array to sort.
 * @param current_pos Current position where to place the maximum element.
 * 
 * @return void
 */
void selection_sort_recursive(unsigned char *array, unsigned int size, unsigned int current_pos) {
    // Base case: if one element or less remains
    if (current_pos >= size - 1) {
        return;
    }
    // printf("Sorting from position %d to %d\n", current_pos, size - 1);
    
    // Variables to get information about maximum and minimum elements
    unsigned int max_index, min_index;
    unsigned char max_value, min_value;
    
    // Find both maximum and minimum elements in the remaining part of array
    get_max_min_index_and_values(array + current_pos, size - current_pos, 
                                 &max_index, &min_index, &max_value, &min_value);

    // printf("Max: %d at index %d, Min: %d at index %d\n", 
    //        max_value, max_index + current_pos, min_value, min_index + current_pos);

    
    // Adjust indices relative to the entire array
    max_index += current_pos;
    min_index += current_pos;
    unsigned int end_pos = size - 1;
    
    // Special case: if max element is at the last position and min at the first,
    // we need to handle this during swaps
    if (max_index == end_pos && min_index == current_pos) {
        // Simply swap beginning and end
        swap(&array[current_pos], &array[end_pos]);
    } else {
        // First, place maximum element at the beginning
        if (max_index != current_pos) {
            swap(&array[current_pos], &array[max_index]);
            // If minimum element was at current_pos position,
            // it has now moved to max_index position
            if (min_index == current_pos) {
                min_index = max_index;
            }
        }
        
        // Then, place minimum element at the end
        if (min_index != end_pos) {
            swap(&array[min_index], &array[end_pos]);
        }
    }

    // printf("Short array after swap: ");
    // print_array(array, size);

    
    // Recursively sort the remaining part of array (exclude one element from each side)
    selection_sort_recursive(array, size - 1, current_pos + 1);
}

/**
 * @brief sort array
 *
 * A function that sorts an array in descending order using recursive selection sort.
 * Uses existing get_max_min_index_and_values() and swap() functions.
 *
 * @param array Pointer to the array of unsigned char values.
 * @param size Size of the array.
 * 
 * @return void
 */
void sort_array(unsigned char *array, unsigned int size) {
    // Check for NULL or empty array
    if (array == NULL || size == 0) {
        return;
    }
    // Start the recursive selection sort from the beginning of the array
    // printf("Starting sort_array with size %d\n", size);
    selection_sort_recursive(array, size, 0);
}

void print_statistics(unsigned char *array, unsigned int size){
#ifdef VERBOSE
  if (array == NULL || size == 0) {
    PRINTF("Error: Array is empty or NULL\n");
    return;
  }

  unsigned char min __attribute__((unused)) = find_minimum(array, size);
  unsigned char max __attribute__((unused)) = find_maximum(array, size);
  unsigned char mean __attribute__((unused)) = find_mean(array, size);
  unsigned char median __attribute__((unused)) = find_median(array, size);

  PRINTF("Statistics:\n");
  PRINTF("Minimum: %d\n", min);
  PRINTF("Maximum: %d\n", max);
  PRINTF("Mean: %d\n", mean);
  PRINTF("Median: %d\n", median);
  sort_array(array, size);
  PRINTF("Sorted \n");
  print_array(array, size);
  PRINTF("Done\n");
#else
  (void)array; // Suppress unused parameter warning
  (void)size;  // Suppress unused parameter warning

#endif
  // If VERBOSE is not defined, do nothing
  // This allows the function to be called without printing anything
  // when VERBOSE is not defined, which is useful for non-debug builds.    
}