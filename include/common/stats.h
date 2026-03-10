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
 * @brief interface of stats.c
 *
 *  this header file contains function declarations
 *
 * @author Nguyen Khac Thai Khang   
 * @date 18/1/2026 (day/month/year)
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief declare print_statistics function
 *
 * print_statistics() - A function that prints the statistics of an array including minimum, 
 * maximum, mean, and median.
 *
 * @param arr pointer to a array
 * @param arr_size the size of array

 * @return void
 */
void print_statistics(unsigned char* arr, int arr_size);

/**
 * @brief declare printf_array function
 *
 * Given an array of data and a length, prints the array to the screen
 *
 * @param arr pointer to a array
 * @param arr_size the size of array

 * @return void
 */
void printf_array(unsigned char* arr, int arr_size);

/**
 * @brief declare find_median function
 *
 * Given an array of data and a length, returns the median value
 * median value that is the middle of the dataset after sorting
 *
 * @param arr pointer to a array
 * @param arr_size the size of array

 * @return unsigned int
 */
unsigned int find_median(unsigned char* arr, int arr_size);

/**
 * @brief declare find_mean function
 *
 * Given an array of data and a length, returns the median value
 * mean value that is the average value of the dataset after sorting
 *
 * @param arr pointer to a array
 * @param arr_size the size of array

 * @return unsigned int
 */
unsigned int find_mean(unsigned char* arr, int arr_size);

/**
 * @brief declare find_maximum function
 *
 * Given an array of data and a length, returns the maximum
 *
 * @param arr pointer to a array
 * @param arr_size the size of array

 * @return unsigned char
 */
unsigned char find_maximum(unsigned char* arr, int arr_size);

/**
 * @brief declare find_minimum function
 *
 * Given an array of data and a length, returns the minimum
 *
 * @param arr pointer to a array
 * @param arr_size the size of array

 * @return unsigned char
 */
unsigned char find_minimum(unsigned char* arr, int arr_size);

/**
 * @brief declare sort_array function
 *
 * Given an array of data and a length, sorts the array from largest to smallest.
 * (The zeroth Element should be the largest value, and the last element (n-1) should be the smallest value. )

 * @param arr pointer to a array
 * @param arr_size the size of array

 * @return void
 */
void sort_array(unsigned char* arr, int arr_size);

#endif /* __STATS_H__ */
