/*// C program to demonstrate setdate() method

#include <dos.h>
#include <time.h>
*/
#include <stdio.h>
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

#include <string.h>
#include <stdio.h>

int main()
{
    char s[10];
    char temp[10];
    scanf("%s %s",s,temp);
    if(strcmp(&s[0],&temp[0]) == 0)
    {
        printf("Same");
        return 0;
    }
    return 1;
}