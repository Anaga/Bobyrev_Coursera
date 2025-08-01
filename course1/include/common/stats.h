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
 * @file stats.h
 * @brief Header file for statistics functions, public functions
 *
 * This file contains the declarations of functions to calculate and print
 * statistics such as minimum, maximum, mean, and median from an array of   
 * unsigned char values.
 * 
 * This file is part of a course project for learning embedded software
 * development. 
 *  
 *
 * @author Aleksandr Bobyrev
 * @date 12.07.2025
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief print statistics - Minimum, Maximum, Mean, Median
 *
 *  A function that prints the statistics of an array including minimum, maximum, mean, and median.
 *
 * @param array Pointer to the array of unsigned char values.
 * @param size Size of the array.
 * 
 * @return void
 */
void print_statistics(unsigned char *array, unsigned int size);


/**
 * @brief print array
 *
 *  A function that prints all elements of an array.
 *
 * @param array Pointer to the array of unsigned char values.
 * @param size Size of the array.
 * 
 * @return void
 */
void print_array(unsigned char *array, unsigned int size);


/**
 * @brief find median
 *
 *  A function that finds the median value of an array.
 *
 * @param array Pointer to the array of unsigned char values.
 * @param size Size of the array.
 * 
 * @return The median value as an unsigned char.
 */
unsigned char find_median(unsigned char *array, unsigned int size);


/**
 * @brief find mean
 *
 *  A function that calculates the mean value of an array.
 *
 * @param array Pointer to the array of unsigned char values.
 * @param size Size of the array.
 * 
 * @return The mean value as an unsigned char.
 */
unsigned char find_mean(unsigned char *array, unsigned int size);


/**
* @brief find maximum
*
*  A function that finds the maximum value in an array.
*
* @param array Pointer to the array of unsigned char values.
* @param size Size of the array.
* 
* @return The maximum value as an unsigned char.
*/
unsigned char find_maximum(unsigned char *array, unsigned int size);


/**
 * @brief find minimum
 *
 *  A function that finds the minimum value in an array.
 *
 * @param array Pointer to the array of unsigned char values.
 * @param size Size of the array.
 * 
 * @return The minimum value as an unsigned char.
 */
unsigned char find_minimum(unsigned char *array, unsigned int size);


/**
 * @brief sort array
 *
 *  A function that sorts an array in descending order.
 *
 * @param array Pointer to the array of unsigned char values.
 * @param size Size of the array.
 * 
 * @return void
 */
void sort_array(unsigned char *array, unsigned int size);


#endif /* __STATS_H__ */
