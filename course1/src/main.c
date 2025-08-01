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
 * @file main.c
 * @brief Main entry point to the C1M4 Assessment
 *
 * This file contains the main code for the C1M4 assesment. 
 *
 */
#include "platform.h"
#include "memory.h"

#ifdef COURSE1
  #include "course1.h"
#endif


/* A simple main file to only call the course1 function */
int main(void) {

  #ifdef COURSE1
  course1();
  #endif

  return 0;
}

