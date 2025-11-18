/*------------------------------------------------------
* Filename: Encryption_EmilyLuskin.c
* Description: This program decrypts a message by performing a series of
*              transformations on an array of 26 integers input by the user.
* Author: Emily Luskin
-------------------------------------------------------*/
#include <stdio.h>
#define ARR_SIZE 26

/*------------------------------------------------------
* Function Name - swap_half
*
* Function Purpose - Swaps the first half of the array with the second half
* Parameters –  [IN numbers - an array of integers]
*
* Return Values - void
*
* Author - Emily Luskin
-------------------------------------------------------*/
void swap_half(int numbers[]) {
    for(int i=0; i<ARR_SIZE/2; i++){
        int temp= numbers[i];
        numbers[i]= numbers[i + ARR_SIZE / 2];
        numbers[i + ARR_SIZE / 2]= temp;
    }
}


/*------------------------------------------------------
* Function Name - decrease_by_previous
*
* Function Purpose - Decreases each element in the array by the value of the previous element
*
* Parameters –  [IN numbers - an array of integers]
*
* Return Values - void
*
* Author - Emily Luskin
-------------------------------------------------------*/
void decrease_by_previous(int numbers[]){
    for(int i=1; i<ARR_SIZE; i++){
        numbers[i]= numbers[i]- numbers[i-1];
    }
}


/*------------------------------------------------------
* Function Name - shift_right
*
* Function Purpose - Shifts the elements of the array to the right by a specified number of positions
*
* Parameters –  [IN numbers - an array of integers]
*
* Return Values - void
*
* Author - Emily Luskin
-------------------------------------------------------*/
void shift_right(int numbers[], int shift) {
    int temp[ARR_SIZE];
    shift = (shift % ARR_SIZE + ARR_SIZE) % ARR_SIZE;
    for (int i = 0; i < ARR_SIZE; i++) {
        temp[(i + shift) % ARR_SIZE] = numbers[i];
    }
    for (int i = 0; i < ARR_SIZE; i++) {
        numbers[i] = temp[i];
    }
}


/*------------------------------------------------------
* Function Name - shift_left
*
* Function Purpose - Shifts the elements of the array to the left by a specified number of positions
*
* Parameters –  [IN numbers - an array of integers]
*
* Return Values - void
*
* Author - Emily Luskin
-------------------------------------------------------*/
void shift_left(int numbers[], int shift) {
    int temp[ARR_SIZE];
    shift = (shift % ARR_SIZE + ARR_SIZE) % ARR_SIZE;
    for (int i = 0; i < ARR_SIZE; i++) {
        temp[i] = numbers[(i + shift) % ARR_SIZE];
    }
    for (int i = 0; i < ARR_SIZE; i++) {
        numbers[i] = temp[i];
    }
}


/*------------------------------------------------------
* Function Name - devide_even
*
* Function Purpose - Divides the elements at even index a specified divisor
*
* Parameters –  [IN numbers - an array of integers]
*
* Return Values - void
*
* Author - Emily Luskin
-------------------------------------------------------*/
void devide_even(int numbers[], int divisor){
    for(int i=0; i<ARR_SIZE; i+=2){
        numbers[i]= numbers[i]/divisor;
    }
}


/*------------------------------------------------------
* Function Name - decrease_by
*
* Function Purpose - Decreases each element in the array by a specified decrement
*
* Parameters –  [IN numbers - an array of integers]
*
* Return Values - void
*
* Author - Emily Luskin
-------------------------------------------------------*/
void decrease_by(int numbers[], int decrement){
    for(int i=0; i<ARR_SIZE; i++){
        numbers[i]= numbers[i]- decrement;
    }
}

int main() {
    int numbers[ARR_SIZE];
    char decrypted_message[ARR_SIZE + 1];
    printf("Enter 26 numbers: ");
    for (int i = 0; i < ARR_SIZE; i++) {
        scanf("%d", &numbers[i]);
    }
    swap_half(numbers);
    decrease_by_previous(numbers);
    shift_right(numbers, 5);
    devide_even(numbers, 7);
    shift_left(numbers, 4);
    decrease_by(numbers, 5);
    for(int i=0; i<ARR_SIZE; i++){
        decrypted_message[i]= (char)numbers[i];
    }
    decrypted_message[ARR_SIZE] = '\0';
    printf("%s", decrypted_message);
    return 0;
}