/*------------------------------------------------------
* Filename: RemoveDup_EmilyLuskin.c
* Description: The program removes dups in different ways
* Author: Emily Luskin
-------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

/*------------------------------------------------------
* Function Name - PrintArr
*
* Function Purpose - Prints the elements of an integer array.
*
* Parameters –  [IN arr - pointer to the arr, IN size - size of the arr]
*
* Return Values - void
*
* Author - Emily Luskin
-------------------------------------------------------*/
void PrintArr(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/*------------------------------------------------------
* Function Name - remove_dup1
*
* Function Purpose - Removes duplicate elements from a sorted array.
* Creates a new dynamic array , returns pointer  and updating the new size.
*
* Parameters –  [IN arr - pointer to array, IN size - size of original arr,
*                 OUT newSize - pointer to store size of new array]
*
* Return Values - int* (pointer to new dynamic array)
*
* Author - Emily Luskin
-------------------------------------------------------*/
int* remove_dup1(int* arr, int size, int* newSize) {
    if (size == 0) {
        *newSize = 0;
        return NULL;
    }

    int* newArr = (int*)malloc(size * sizeof(int));
    if (newArr==NULL) {
        *newSize = 0;
        return NULL;
    }

    int j = 0;
    newArr[j++] = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] != arr[i - 1]) {
            newArr[j++] = arr[i];
        }
    }
    *newSize = j;
    return newArr;
}

/*------------------------------------------------------
* Function Name - remove_dup2
*
* Function Purpose - Removes duplicate elements from a sorted array.
* Returns the new array size, and passes the pointer to the new array.
*
* Parameters –  [IN arr - pointer to original array, IN size - size of original array,
*                 OUT newArr - pointer to store pointer to new dynamic array]
*
* Return Values - int (size of new array)
*
* Author - Emily Luskin
-------------------------------------------------------*/
int remove_dup2(int* arr, int size, int** newArr) {
    if (size == 0) {
        *newArr = NULL;
        return 0;
    }

    *newArr = (int*)malloc(size * sizeof(int));
    if (!*newArr) return 0;

    int j = 0;
    (*newArr)[j++] = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] != arr[i - 1]) {
            (*newArr)[j++] = arr[i];
        }
    }
    return j;
}

/*------------------------------------------------------
* Function Name - remove_dup3
*
* Function Purpose - Removes duplicate elements from a sorted array.
* Does not return anything; passes both the pointer to the new array and its size.
*
* Parameters –  [IN arr - pointer to original array, IN size - size of original array,
*                 OUT newArr - pointer to store pointer to new dynamic array,
*                 OUT newSize - pointer to store size of new array]
*
* Return Values - void
*
* Author - Emily Luskin
-------------------------------------------------------*/
void remove_dup3(int* arr, int size, int** newArr, int* newSize) {
    if (size == 0) {
        *newArr = NULL;
        *newSize = 0;
        return;
    }

    *newArr = (int*)malloc(size * sizeof(int));
    if (!*newArr) {
        *newSize = 0;
        return;
    }

    int j = 0;
    (*newArr)[j++] = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] != arr[i - 1]) {
            (*newArr)[j++] = arr[i];
        }
    }
    *newSize = j;
}

int main() {
    int arr[] = {1, 1, 2, 2, 3, 4, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("OG array:\n");
    PrintArr(arr, size);

    int newSize1;
    int* newArr1 = RemoveDup1(arr, size, &newSize1);
    printf("RemoveDup1 result:\n");
    PrintArr(newArr1, newSize1);
    free(newArr1);

    int* newArr2;
    int newSize2 = RemoveDup2(arr, size, &newArr2);
    printf("RemoveDup2 result:\n");
    PrintArr(newArr2, newSize2);
    free(newArr2);

    int* newArr3;
    int newSize3;
    RemoveDup3(arr, size, &newArr3, &newSize3);
    printf("RemoveDup3 result:\n");
    PrintArr(newArr3, newSize3);
    free(newArr3);

    return 0;
}