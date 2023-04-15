/*// C program to demonstrate setdate() method

#include <dos.h>
#include <time.h>
*/
#include <stdio.h>
#include <stdlib.h>
/*
int main()
{
	//struct date *dt = getdate(&dt);
    time_t _time = time(NULL);
    struct tm Today = *localtime(&_time);
    printf("\nThis program has been written at (date and time): %d \nmday= %d\nwday %d\nyday %d ", Today.tm_year+1900,Today.tm_mday,Today.tm_wday,Today.tm_yday);
	
	return 0;
}
*/

/*#include <time.h>

struct timeval stop, start;
gettimeofday(&start, NULL);
//do stuff
gettimeofday(&stop, NULL);
printf("took %lu us\n", (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec); */


/*int main()
{
    float n;
    int num[10]={0},i;
    for(i=0;i<10;i++)
    {
        printf("Enter Numbers: ");
        scanf("%f", &n);
        num[i]=n;
    }
}*/

//#include <string.h>
//#include <stdio.h>
//
//int main()
//{
//    char s[10];
//    char temp[10];
//    scanf("%s %s",s,temp);
//    if(strcmp(&s[0],&temp[0]) == 0)
//    {
//        printf("Same");
//        return 0;
//    }
//    return 1;
//}
#define pass (void)0
enum Bool {false, true};
enum Bool Direction = false;

void swaplok(int *x,int *y);
int HEIGHT=768,WIDTH = 1024;

void main()
{
    int a = 512,b=380;
    printf("Ball position before: %d %d\n",a,b);
    swaplok(&a,&b);//&firstFlag,
    printf("Ball position AFTER: %d %d\n",a,b);
    scanf("%d",&a);
    return;
}

// Updates tthe position of the ball to new random value
void swaplok(int *xpos,int *ypos)//enum Bool *firstFlag,
{
    int randomNo = (rand() % 3);
    //firstFlag? (Direction = rand()%2)&&(firstFlag = false) : pass;
    if(Direction)
    {
        if (randomNo == 0)
        {
            if(*xpos<0)
            {
                Direction = false;
            }
            else
            {
                *xpos-=100;
            }
        }
        else if(randomNo == 1)
        {
            if(*xpos<0)
            {
                Direction = false;
            }
            else
            {
                *xpos-=100;
            }
            (*ypos>HEIGHT)? pass : (*(ypos)+=100);
        }
        else
        {
            if(*xpos<0)
            {
                Direction = false;
            }
            else
            {
                *xpos-=100;
            }
            (*ypos<0)? pass : (*(ypos)-=100);
        }
    }
    else
    {
        if (randomNo == 0)
        {
            if(*xpos>WIDTH)
            {
                Direction = true;
            }
            else
            {
                *xpos+=100;
            }
        }
        else if(randomNo == 1)
        {
            if(*xpos>WIDTH)
            {
                Direction = true;
            }
            else
            {
                *xpos+=100;
            }
            (*ypos>HEIGHT)? pass : (*(ypos)+=100);
        }
        else
        {
            if(*xpos>WIDTH)
            {
                Direction = true;
            }
            else
            {
                *xpos+=100;
            }
            (*ypos<0)? pass : (*(ypos)-=100);
        }
    }
    printf("Ball position changed to %d %d\n",*xpos,*ypos);
    return;
}