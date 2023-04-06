#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//Function for f(lmn) = l!+m!+n!
//Function for s(mn) = m+n
//sf(lm) = n
//s(f(25)) = s(122) = 5
//g(n) = lm
//g(5) = 25
//for finding g we need to find sf(1-nnnnn) == 5
//Function for g(n) = sf(lm)
//return sg(n) = s(lm) = l+m
//if 3 we need to return g(1)+g(2)+g(3)
//if n we need to return for(i=0;i<n;i++){sum+=g(i);};
char* ldtoc(long int n,int* count);
long int f(char* n,int count);
long int s(char* n,int count);
long int fact(int n);
void display(char* num,int count);

int main() {
    int q,i;
    long int n,temp;
    int count=0;
    scanf("%d",&q);
    for (i=0;i<q;i++)
    {
        scanf("%ld",&n);
        temp = n;
        do{
            temp/=10;
            count++;
        }while(temp!=0);
        //printf("Count : %d\n",count);
        char num[count];
        //printf("Before size: %d\n",sizeof(num));
        temp = n;
        for (int i=0;i<count;i++)
        {
            num[i] = temp%10;
            temp/=10;
        }
        long int factofdigits = f(num,count);
        printf("f(n): %d\n",factofdigits);
        s(ldtoc(factofdigits,&count),count);
    }
    getch();
    return 0;
}


char* ldtoc(long int n,int* count)
{
    char num[*count];
    int i=0;
    do{
        num[i] = n%10;
        n/=10;
        i++;
    }while(n!=0);
    *(&count) = i;
    return num;
}


long int f(char* n,int count)
{
    long int sum = 0;
    for (long int i = 0;i<count;i++)
    {
        sum += fact((int)n[i]);
    }
    return sum;
}


long int s(char* n,int count)
{
    long int sum = 0;
    for (int i = 0;i<count;i++)
    {
        sum += (int)n[i];
    }
    return sum;
}


long int fact(int n)
{
    long int facto = 1;
    for (long int i = 1;i<=n;i++)
    {
        facto *= i;
    }
    printf("%d! = %ld\n",n,facto);
    return facto;
}

void display(char* num,int count)
{
    for (int i=0;i<count;i++)
    {
        printf("%d\n",num[i]);
    }
}