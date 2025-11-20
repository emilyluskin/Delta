/*------------------------------------------------------
* Filename:aa
* Description: 
* Author: Emily Luskin
-------------------------------------------------------*/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#define ARR_SIZE 5
char* dyn_scanf(void); //note-- I copied the code from the previous question
const int compare_by_alpha(const void *str1, const void *str2);
const int compare_by_len(const void *str1, const void *str2);
void sort (void ** arr, size_t size, int (*compare)(const void*, const void*));

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
    while(((ch=getchar())!='\n') && (ch!=EOF) ){
        if (ch == '\r') continue; 
        char *temp =(char*) realloc(str, (size+2) * sizeof(char));
        if(temp==NULL){
            free(str);
            return NULL;
        }
        str= temp;
        str[size]=(char)ch;
        size++;
        str[size]='\0';
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

/*------------------------------------------------------
* Function Name - compare_by_alpha
*
* Function Purpose - compares between 2 strings by alpha
*
* Parameters –  [IN void*, void*]
*
* Return Values - int - 1/-1/0
*
* Author - Emily Luskin
-------------------------------------------------------*/
const int compare_by_alpha(const void *str1, const void *str2){
    int cmp=0;
    const char *s1 = (const char *)str1; 
    const char *s2 = (const char *)str2;
    if(s1 == NULL && s2==NULL){
        return 0;
    }
    if( s1== NULL){
        return -1;
    }
    if( s2==NULL){
        return 1;
    }
    cmp = strcmp(s1, s2);
    if(cmp>0){
        return 1;
    }
    if(cmp<0){
        return -1;
    }
    return 0;
}


/*------------------------------------------------------
* Function Name - compare_by_len
*
* Function Purpose - compares between 2 strings by length
*
* Parameters –  [IN void*, void*]
*
* Return Values - int - 1/-1/0
*
* Author - Emily Luskin
-------------------------------------------------------*/
const int compare_by_len(const void *str1, const void *str2){
    const char *s1 = (const char *)str1;
    const char *s2 = (const char *)str2;
    if(s1 == NULL && s2==NULL){
        return 0;
    }
    if( s1== NULL){
        return -1;
    }
    if( s2==NULL){
        return 1;
    }
    size_t s1_len = strlen(s1);
    size_t s2_len = strlen(s2);
    if(s1_len>s2_len){
        return 1;
    }
    if(s1_len<s2_len){
        return -1;
    }
    return 0;
}


/*------------------------------------------------------
* Function Name - sort
*
* Function Purpose - sorts generically , the user decides what function to use
*
* Parameters –  [IN void**, size_t, pointer to function]
*
* Return Values - void
*
* Author - Emily Luskin
-------------------------------------------------------*/
void sort(void ** arr, size_t size, int (*compare)(const void*, const void*)){
    for(int i=0; i<size-1; i++){
        for(int j=0; j< size-i-1; j++){
            if(compare(arr[j],arr[j+1])>0){
                void *temp = arr[j+1];
                arr[j+1]= arr[j];
                arr[j]= temp;
            }
        }
    }
}

int main(){
    char *arr[ARR_SIZE];
    
    printf("Enter %d strings:\n", ARR_SIZE);
    for (int i = 0; i < ARR_SIZE; i++)
    {
        arr[i] = dyn_scanf();
        if (arr[i]== NULL)
        {
            printf("Memory allocation error!\n");
            return 1;
        }
    }
    printf("Sorted by length: \n");
    sort((void**)arr, ARR_SIZE, compare_by_len);
    for (int i = 0; i < ARR_SIZE; i++)
    {
        printf_s("%s", arr[i]);
        if (i < ARR_SIZE-1) printf(",");
    }
    printf("\n");

    printf("Sorted by alpha: \n");
    sort((void**)arr, ARR_SIZE, compare_by_alpha);
    for (int i = 0; i < ARR_SIZE; i++)
    {
        printf("%s", arr[i]);
        if (i < ARR_SIZE-1) printf(",");
    }
    printf("\n");

    for (int i = 0; i < ARR_SIZE; i++)
        free(arr[i]);

    return 0;
}