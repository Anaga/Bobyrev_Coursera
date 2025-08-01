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
#ifndef __PLATFORM_H__
#define __PLATFORM_H__

/******************************************************************************
 Platform - MSP432
******************************************************************************/
#if defined (MSP432)
#include "msp432p401r.h"
#define PRINTF(...) // No standard output for MSP432

/******************************************************************************
 Platform - HOST
******************************************************************************/
#elif defined (HOST)
#include <stdio.h>
#ifdef VERBOSE
  #define PRINTF(...) printf(__VA_ARGS__)
#else
  #define PRINTF(...)
#endif

/******************************************************************************
 Platform - Unsupported
******************************************************************************/
#else
#error "Platform provided is not supported in this Build System"
#endif

#endif /* __PLATFORM_H__ */

