#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <stdbool.h>

#define Width 43
#define Height 156
int main()
{
    int screen[Width][Height]={0};
    int i,j;
    screen[22][78] = 8;
    FILE * faSnake = fopen("SnakeGame\\Scores.txt", "a");
    FILE * frSnake = fopen("SnakeGame\\Scores.txt", "r");
    printf("Here");
    while(1)
    {
        Sleep(50);
        system("cls");
        for(i=0;i<Width;i++)
        {
            for(j=0;j<Height;j++)
            {
                if (screen[i][j] == 0)
                {
                    printf("%c",' ');
                }
                else
                {
                    printf("%d",screen[i][j]);
                }
            }
            printf("\n");
        }
    }
    printf("There");
    fclose(faSnake);
    fclose(frSnake);
}