/**
 ******************************************************************************
 * @file data.h
 *
 * @brief interface of data.c
 This file contains the declaration of functions in data.c
 *
 *@author Nguyen Khac Thai Khang
 *
 * @date 03/10/2026 (day/month/year)
*
******************************************************************************
*/

#ifndef _DATA_H
#define _DATA_H
#include <stdint.h>

/**
 *@brief the function converts data from standard integer type into an ASCII string
 *
 * @param data: the integerdata that we want to convert
 *
 * @param ptr: the pointer to the buffer where we want to store the
 * 
 * @param base: the base of the number system that we want to convert to
 *
 * @return the length of the converted data
*/
uint8_t myitoa(uint8_t * ptr, uint8_t digits, uint32_t base);

/**
 *@brief the function converts data from ASCII string into an standard integer type
 *
 * @param digits: The number of digits in your character set is passed in as a uint8_t integer (digits). 
 *
 * @param ptr: The character string to convert is passed in as a uint8_t * pointer (ptr)
 * 
 * @param base: the base of the number system that we want to convert to
 *
 * @return The converted 32-bit signed integer should be returned.
*/
int32_t myatoi(uint8_t* ptr, uint8_t digits, uint32_t base);


#endif /* _DATA_H */