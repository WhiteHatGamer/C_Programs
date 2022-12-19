#include <stdio.h>
#include <string.h>
void main()
{
    FILE * fpointer = fopen("Morse_code_translator\\MST.txt", "a");
    char message[25];
    printf("Enter the Message:");
    //scanf("%[^\n]",&message);
    gets(message);
    fprintf(fpointer, (strcat(message, "\n")));
    printf("The Message is %s",&message);
    fclose(fpointer);
}