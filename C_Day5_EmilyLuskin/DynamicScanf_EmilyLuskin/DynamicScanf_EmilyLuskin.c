/*------------------------------------------------------
* Filename: DynamicScanf_EmilyLuskin.c
* Description: The program is using dyn_scanf function and Reads text line and returns dynamic allocation of string
* Author: Emily Luskin
-------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
char* dyn_scanf(void);
/*------------------------------------------------------
* Function Name - dyn_scanf
*
* Function Purpose - Reads text line and returns dynamic allocation of string
*
* Parameters –  [IN void]
*
* Return Values - char*
*
* Author - Emily Luskin
-------------------------------------------------------*/
char* dyn_scanf(void){
    char *str = NULL;
    int size=0, ch;
    ch=getchar();
    while( (ch!='\n') && (ch!=EOF) ){
        char *temp =(char*) realloc(str, (size+2) * sizeof(char));
        if(temp==NULL){
            free(str);
            return NULL;
        }
        str= temp;
        str[size]=(char)ch;
        size++;
        str[size]='\0';
        ch=getchar();
    }

    if(str == NULL){
        str = (char *) malloc(sizeof(char)*1);
        if(str==NULL){
            return NULL;
        }
        str[0]='\0';
    }
    return str;
}

int main(){
    char *str = NULL;
    printf("Please enter input: \n");
    str=dyn_scanf();
    if (str == NULL){
        printf("Memory Allocation Error! \n");
        return 1;
    }
    printf_s("You Wrote : %s \n", str);
    free(str);
    return 0;
}