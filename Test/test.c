#include <stdio.h>
#include <conio.h>
#include <stdbool.h>

void main(void) {
    while(true)
    {
        int a[5];
        int i, n;
        for(i=0;i<5;i++)
        {
            printf("%lf\n",scanf("%d",&a[i]));
            break;
        }
        n = i;
        for(i=0;i<n;i++)
            printf("%d\n",a[i]);
    }
}