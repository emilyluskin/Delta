/*------------------------------------------------------
* Filename: ArraySort_EmilyLuskin.c
* Description: the program sorts an array of integers using pointers
* Author: Emily Luskin
-------------------------------------------------------*/
#include <stdio.h>
#define ARR_SIZE 10

/*------------------------------------------------------
* Function Name - print_addresses_and_values
*
* Function Purpose - Prints the addresses and values of the elements in the array
*
* Parameters –  [IN num_ptr - pointer to an array of integer pointers]
*
* Return Values - void
*
* Author - Emily Luskin
-------------------------------------------------------*/
void print_addresses_and_values(int *num_ptr[]){
    for(int i=0; i<ARR_SIZE; i++){
        printf("%d- Value: %d  Address: %p\n",i+1, *num_ptr[i], num_ptr[i]);
    }
}
/*------------------------------------------------------
* Function Name - swap
*
* Function Purpose - Swaps two integer pointers
*
* Parameters –  [IN p1 - pointer to first integer pointer, IN p2 - pointer to second integer pointer]
*
* Return Values - void
*
* Author - Emily Luskin
-------------------------------------------------------*/
void swap(int** p1, int** p2){
    int* temp= *p1;
    *p1= *p2;
    *p2= temp;
}

int main() {
    int numbers[ARR_SIZE];
    int *numbers_ptr[ARR_SIZE];
    for(int i=0; i<ARR_SIZE; i++){
        numbers_ptr[i]= &numbers[i];
    }
    for(int i=0; i<ARR_SIZE; i++){
        printf("Enter integer %d: ", i+1);
        while(scanf("%d", &numbers[i]) != 1) {
            printf("Invalid input. Try again: ");
            while(getchar() != '\n');
        }
    }
    printf("-----BEFORE SORTING -----\n");
    print_addresses_and_values(numbers_ptr);

    for(int i=0; i<ARR_SIZE-1; i++){
        for(int j=i+1; j<ARR_SIZE; j++){
            if(*numbers_ptr[j] < *numbers_ptr[i]){
                swap(&numbers_ptr[i], &numbers_ptr[j]);
            }
        }
    }
    
    printf("-----AFTER SORTING -----\n");
    print_addresses_and_values(numbers_ptr);
    return 0;
}