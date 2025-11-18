/*------------------------------------------------------
* Filename: PrintValueAddr_EmilyLuskin.c
* Description: program that prints the values and addresses of elements in integer and character arrays
* Author: Emily Luskin
-------------------------------------------------------*/
#include <stdio.h>
#define ARR_SIZE 8
/*------------------------------------------------------
* Function Name - print_value_address
*
* Function Purpose - Prints the values and addresses of elements in integer and character arrays
*
* Parameters –  [IN numbers - an array of integers, IN chars - an array of characters]
*
* Return Values - void
*
* Author - Emily Luskin
-------------------------------------------------------*/
void print_value_address(int numbers[], char chars[]){
    printf("Arr of integers:\n");
    for(int i=0; i<ARR_SIZE; i++){
        printf("%d - The values is %d , address is %p\n", i, numbers[i], &numbers[i]);
    }
    printf("Arr of characters:\n");
    for(int i=0; i<ARR_SIZE; i++){
        printf("%d - The values is %c , address is %p\n", i, chars[i], &chars[i]);  
    }
}

/*------------------------------------------------------
* Function Name -   print_value_address_ptr
*
* Function Purpose - Prints the values and addresses of elements in integer and character arrays
*
* Parameters –  [IN num_ptr - pointer to an array of integers, IN char_ptr - pointer to an array of characters]
*
* Return Values - void
*
* Author - Emily Luskin
-------------------------------------------------------*/
void print_value_address_ptr(int *num_ptr, char *char_ptr){
    printf("Arr of integers:\n");
    for(int i=0; i<ARR_SIZE; i++){
        printf("%d - The values is %d , address is %p\n", i, *(num_ptr + i), (num_ptr + i));
    }
    printf("Arr of characters:\n");
    for(int i=0; i<ARR_SIZE; i++){
        printf("%d - The values is %c , address is %p\n", i, *(char_ptr + i), (char_ptr + i));  
    }
}

int main(){
    int numbers[ARR_SIZE];
    char chars[ARR_SIZE];
    for(int i=0; i<ARR_SIZE; i++){
        printf("Enter integer %d: ", i+1);
        //check if the input is good
        while(scanf("%d", &numbers[i]) != 1) {
            printf("Invalid input. Try again: ");
            while(getchar() != '\n');
        }
    }
    for(int i=0; i<ARR_SIZE; i++){
        printf("Enter character %d: ", i+1);
        scanf(" %c", &chars[i]);
    }
    print_value_address(numbers, chars);
    print_value_address_ptr(numbers, chars);
    return 0;
}