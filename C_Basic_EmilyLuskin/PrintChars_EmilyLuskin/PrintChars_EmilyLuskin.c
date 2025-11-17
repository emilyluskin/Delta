/*------------------------------------------------------
* Filename:PrintChars_EmilyLuskin.c
* Description: A program that prints square of characters based on the input integer
* Author: Emily Luskin
-------------------------------------------------------*/
#include <stdio.h>
void print_chars(char ch, int count){
    for(int i=0; i<count; i++){
        printf("%c", ch);
    }
    printf("\n");
}
int main(){
    int num;
    printf("Enter an integer: ");
    if (scanf("%d", &num) != 1 || num <= 0){
        printf("Bad input!\n");
        return 0;
    }
    if(num%2==0){
        for(int i=0; i<num; i++){
            print_chars('*', num);
        }
    }
    else if (num%3==0){
        for(int i=0; i<num; i++){
            print_chars('^', num);
        }
    }
    else if(num%5==0){
        for(int i=0; i<num; i++){
            print_chars('%', num);
        }
    }
    else{
        for(int i=0; i<num; i++){
            print_chars('@', num);
        }
    }
    return 0;
}