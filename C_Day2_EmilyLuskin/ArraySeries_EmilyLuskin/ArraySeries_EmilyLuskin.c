/*------------------------------------------------------
* Filename: ArraySeries_EmilyLuskin.c
* Description: A program that checks if an array of integers is increasing, decreasing, constant, or messed up
* Author: Emily Luskin
-------------------------------------------------------*/
#include <stdio.h>
#define ARRAY_SIZE 15

/*------------------------------------------------------
* Function Name - check_array_series
*
* Function Purpose - Checks if an array of integers is increasing, decreasing, constant, or messed up
*
* Parameters –  [IN arr - an array of integers]
*
* Return Values - void
*
* Author - Emily Luskin
-------------------------------------------------------*/

void check_array_series(int arr[]) {
    int increasing = 0, decreasing = 0, equal = 0;

    for(int i = 0; i < ARRAY_SIZE - 1; i++) {
        if(arr[i] < arr[i+1])
            increasing++;
        else if(arr[i] > arr[i+1])
            decreasing++;
        else
            equal++;
    }

    if(increasing == ARRAY_SIZE - 1)
        printf("The array is increasing.\n");
    else if(decreasing == ARRAY_SIZE - 1)
        printf("The array is decreasing.\n");
    else if(equal == ARRAY_SIZE - 1)
        printf("The array is constant.\n");
    else
        printf("The array is messed up.\n");
}

int main() {
    int numbers[ARRAY_SIZE];
    printf("Enter %d integers:\n", ARRAY_SIZE);

    for(int i = 0; i < ARRAY_SIZE; i++) {
        scanf("%d", &numbers[i]);
    }

    check_array_series(numbers);
    return 0;
}

