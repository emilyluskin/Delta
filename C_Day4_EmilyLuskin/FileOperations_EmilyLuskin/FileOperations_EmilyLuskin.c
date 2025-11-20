/*------------------------------------------------------
* Filename: FileOperations_EmilyLuskin.c
* Description: this program demonstrates basic file operations in C. 
* Author: Emily Luskin
-------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

void printFileContent(const char* filename);
void copyFileToAnother(const char* source, const char* destination);
void printFileState(const char* filename);
void deleteLineFromFile(const char* filename, int lineToDelete);
int countStringInFile(const char* filename, const char* str);
/*------------------------------------------------------
* Function Name - printFileContent
*
* Function Purpose - Prints the content of file to the console.
*
* Parameters –  [IN filename - pointer to the name of the file]
*
* Return Values - void
*
* Author - Emily Luskin
-------------------------------------------------------*/
void printFileContent(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return;
    }
    char content;
    while ((content = fgetc(file)) != EOF) {
        putchar(content);
    }
    fclose(file);
}

/*------------------------------------------------------
* Function Name - copyFileToAnother
*
* Function Purpose - Copies the content of a source file to a destination file.
*
* Parameters –  [IN source - pointer to the source file name,
*                 IN destination - pointer to the destination file name]
*
* Return Values - void
*
* Author - Emily Luskin
-------------------------------------------------------*/
void copyFileToAnother(const char* source, const char* destination) {
    FILE* srcFile = fopen(source, "r");
    if (srcFile == NULL) {
        printf("Error opening source file: %s\n", source);
        return;
    }
    FILE* destFile = fopen(destination, "w");
    if (destFile == NULL) {
        printf("Error opening destination file: %s\n", destination);
        fclose(srcFile);
        return;
    }
    char content;
    while ((content = fgetc(srcFile)) != EOF) {
        fputc(content, destFile);
    }
    fclose(srcFile);
    fclose(destFile);
}

/*------------------------------------------------------
* Function Name - printFileState
*
* Function Purpose - Prints the number of lines, words, and characters in a file.
*
* Parameters –  [IN filename - pointer to the name of the file]
*
* Return Values - void
*
* Author - Emily Luskin
-------------------------------------------------------*/
void printFileState(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return;
    }
    int lines = 0, words = 0, chars = 0;
    char content;
    int inWord = 0;
    while ((content = fgetc(file)) != EOF) {
        chars++;
        if (content == '\n') {
            lines++;
        }
        if (content == ' ' || content == '\n' || content == '\t') {
            inWord = 0;
        } else if (inWord == 0) {
            inWord = 1;
            words++;
        }
    }
    fclose(file);
    printf("File: %s\nLines: %d\nWords: %d\nCharacters: %d\n", filename, lines, words, chars);
}

/*------------------------------------------------------
* Function Name - deleteLineFromFile
*
* Function Purpose - Deletes a specific line from a file by creating a temp file.
*
* Parameters –  [IN filename - pointer to the name of the file,
*                 IN lineToDelete - line number to delete]
*
* Return Values - void
*
* Author - Emily Luskin
-------------------------------------------------------*/
void deleteLineFromFile(const char* filename, int lineToDelete) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return;
    }
    FILE* tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Error creating temporary file.\n");
        fclose(file);
        return;
    }
    int currentLine = 1;
    char content;
    while ((content = fgetc(file)) != EOF) {
        if (content == '\n') {
            currentLine++;
        }
        if (currentLine != lineToDelete) {
            fputc(content, tempFile);
        }
    }
    fclose(file);
    fclose(tempFile);
    remove(filename);
    rename("temp.txt", filename);
}

/*------------------------------------------------------
* Function Name - countStringInFile
*
* Function Purpose - Counts the shows of a specific string in a file.
*
* Parameters –  [IN filename - pointer to the file name,
*                 IN str - pointer to the string to count]
*
* Return Values - int (number of shows, -1 if error)
*
* Author - Emily Luskin
-------------------------------------------------------*/
int countStringInFile(const char* filename, const char* str) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return -1;
    }
    int count = 0;
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        char* ptr = buffer;
        while ((ptr = strstr(ptr, str)) != NULL) {
            count++;
            ptr += strlen(str);
        }
    }
    fclose(file);
    return count;
}

int main() {
    printFileContent("file.txt");
    copyFileToAnother("file.txt", "copy.txt");
    printFileState("file.txt");
    deleteLineFromFile("file.txt", 2);
    int occ = countStringInFile("file.txt", "my");
    printf("Occurrences: %d\n", occ);
    return 0;
}
