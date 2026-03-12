
/**
 ******************************************************************************
 * @file data.c
 *
 * @brief implementation of data.h
 This file contains the implementation of functions in data.h
 *
 *@author Nguyen Khac Thai Khang
 *
 * @date 03/10/2026 (day/month/year)
 * 
 * 
 */
#include "data.h"
#include "memory.h"
uint32_t power_function(uint32_t base, uint32_t exponent)
{
    uint32_t result = 1;
    for(int i = 0; i < exponent; i++)
    {
        result *= base;
    }
    return result;
}

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
    uint8_t length = 0;
    uint32_t dividend = (uint32_t)data;
    uint32_t quotient = 1;
    while(quotient)
    {
        uint32_t remainder = 0;
        quotient = dividend / base;
        remainder = dividend % base;
        dividend = quotient;
        if(base == 16 && remainder >= 10)
        {
            remainder = remainder - 10 + 'A';
        }
        else
        {
            remainder += '0';
        }
        *(ptr + length) = remainder;
        length++;
    }
    my_reverse(ptr, length - 1);
    *(ptr + length) = '\0';
    return length;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{
    int32_t value = 0;
    for(int i = 0; i < digits - 1; i++)
    {
        if(base == 16 && *(ptr + i) >= 'A')
        {
            value = value + (*(ptr + i) - 'A' + 10) * power_function(base, digits - 2 - i);
        }
        else
        {
            value = value + (*(ptr + i) - '0') * power_function(base, digits - 2 - i);  
        }
    }
    return value;
}


