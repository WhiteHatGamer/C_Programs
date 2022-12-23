#include <stdio.h>
#include <conio.h>
#include <sys/time.h>

int sum(int);

void main()
{
    struct timeval stime, times;
    
    int result,x;
    printf("Enter a Number: ");
    scanf("%d",&x);
    result = sum(x);
    gettimeofday(&stime, NULL);
    printf("Sum of 0 through %d is %d",x,result);
    gettimeofday(&times, NULL);
    printf("\nTook %lu Micro Seconds",(times.tv_sec - stime.tv_sec)*1000000 + (times.tv_usec - stime.tv_usec));
    getch();
}

int sum(int x)
{
    if (x>0)
    {
        return x + sum(x - 1);
    }
    else
    {
        return 0;
    }
    /*int i,result=0;
    for(i=0;i<x;i++)
    {
        result=result+i;
    }
    return result;*/
}