/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
//Linkers
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

//BEWARE IAM USING GETS..ME MYSELF DON'T RECOMMEND USING THIS

//Prototyping
void shitf(char *k,int *index, int *end);
const int MAXIMUM_LENGTH = 150 * 1.5;

//Main Function
void main(void)
{
    //Space complexity Minimized for Time Complexity O(n)
    char Key[MAXIMUM_LENGTH];
    char seperator;
    //char Temp[MAXIMUM_LENGTH];
    while(1)
    {
        system("cls");
        printf("Hello World\n");
        printf("Enter the Code(q to Quit): ");
        //Using gets so we get spaces
        gets(Key);
        if(Key[0]=='q')
        {
            printf("\nAdios");
            getch();
            return;
        }
        printf("Enter Seperator: ");
        scanf("%c",&seperator);
        int n = strlen(Key)+3;
        //gets(Temp);
        //strcat(Key,Temp);
        //
        for (int i=n;i>=0;i--)
        {
            Key[i+2] = Key[i];
        }
        //O(1) Adding Unicode Characters to act as emoji+Ascii
        Key[0] = '&';
        Key[1] = '#';
        //printf("\nThe Given Code Is: ");
        //puts(Key);

        //O(n)//since its conditional 2nd loop
        for (int i = 1;i < n; i++)
        {
            if((int)Key[i] == (int)seperator)
            {
                shitf(Key,&i,&n);
            }
        }
        //Adding Character to end Code
        Key[n-1]=';';
        Key[n] = '\000';
        printf("\nThe ASCII: ");
        puts(Key);
        //IMP::::Required to Clear input Buffer so we can gets again -> fflush
        fflush(stdin);
        getch();
    }
}

//Funtion To shift right 3 times at an index
void shitf(char *k,int *index, int *end)
{
    //O(n)
    for (int i=*end;i>*index;i--)
    {
        k[i+3] = k[i];
    }
    //O(1) Adding Unicode Characters to act as emoji+Ascii
    k[*index] = ';';
    k[*index+1] = ' ';
    k[*index+2] = '&';
    k[*index+3] = '#';
    //Shouldnt repeat for the 2nd space
    *index += 3;
    *end += 3;
}
