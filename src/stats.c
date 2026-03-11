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
 * @brief definition of all functions that were mentioned in header file
 * this file show some basic functions in statistic
 *
 * @author Nguyen Khac Thai Khang
 * @date 18/1/2026
 *
 */

#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() 
{

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
  printf("COMPILE WITHOUT ERROR\n");
  printf("Array before sort:\n");
  printf_array(test,SIZE);
  printf("\n");
  printf("Statistics of dataset\n");
  print_statistics(test, SIZE);
  printf_array(test, SIZE);
}

void print_statistics(unsigned char* arr, int arr_size)
{
  printf("minimum value of array is: %d\n", find_minimum(arr, arr_size));
  printf("maximum value of array is: %d\n", find_maximum(arr, arr_size));
  printf("mean value of array is: %d\n", find_mean(arr,arr_size));
  printf("median value of array is: %d\n", find_median(arr,arr_size));
}

void printf_array(unsigned char* arr, int arr_size)
{
  for(int i = 0; i < arr_size; i++)
  {
    printf("%d ", *(arr + i));
  }
  printf("\n");
}

unsigned int find_median(unsigned char* arr, int arr_size)
{
  sort_array(arr, arr_size);

    if(arr_size % 2 == 1)
    {
        return arr[arr_size / 2];
    }
    else
    {
        return (arr[arr_size / 2 - 1] + arr[arr_size / 2]) / 2.0f;
    }
}

unsigned int find_mean(unsigned char* arr, int arr_size)
{
  unsigned int result = 0;
  for(int i = 0; i < arr_size; i++)
  {
     result += *(arr + i);
  }
  result = result / arr_size;
  return result;
}

unsigned char find_maximum(unsigned char* arr, int arr_size)
{
  unsigned char maximum = 0x00;
  for(int i = 0; i < arr_size; i++)
  {
    maximum = (*(arr + i) > maximum) ? *(arr + i) : maximum;
  }
  return maximum;
}

unsigned char find_minimum(unsigned char* arr, int arr_size)
{
  unsigned char minimum = 0xFF;
  for(int i = 0; i < arr_size; i++)
  {
    minimum = (*(arr + i) < minimum) ? *(arr + i) : minimum;
  }
  return minimum;
}

void sort_array(unsigned char* arr, int arr_size)
{
  // using buble sort
   for(int i = 0; i < arr_size - 1; i++)
    {
        for(int j = 0; j < arr_size - i - 1; j++)
        {
            if(arr[j] < arr[j + 1])   
            {
                unsigned char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


/* Add other Implementation File Code Here */
