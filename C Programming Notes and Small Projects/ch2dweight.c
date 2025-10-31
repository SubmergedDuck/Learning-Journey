/***********************************************************************
* Name: ch2dweight.c                                                   *
* Purpose: Calculating dimensional weight for a shipping container.    *
* Author: SubmergedDuck                                                *
************************************************************************/

// Shipping companies don't like boxes that are large but very light
// Fees are based on volume instead of weight
// In the US, the usual method is to divide the volume by 166, if the number exceeds its weight, the shipping fee is based on the dimensional weight
// International Shipping: 166
// Domestic Shipping: 194
// Dimensional Weight = Volume / 166 
// Shipping company expects us to round up

#include <stdio.h>
#include <math.h>
#define INCHES_PER_POUND 166 // A macro definition for readability
#define RECIPROCAL_OF_PI (1.0f / 3.14159f) // Eg. of a macro def with operators

int main() {
    int length, height, width, volume, weight;
    printf("Enter length of container: ");
    scanf("%d", &length); 
    printf("Enter height of container: ");
    scanf("%d", &height);
    printf("Enter width of container: ");
    scanf("%d", &width);
    volume = length * height * width; 
    weight = (volume + INCHES_PER_POUND - 1) / INCHES_PER_POUND;

    printf("Dimensions: %d x %d x %d \n", length, height, width);
    printf("Volume (cubic inches): %d \n", volume);
    printf("Dimensional weight (pounds): %d \n", weight); 

    return 0; 
}