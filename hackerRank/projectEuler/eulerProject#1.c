#include <stdio.h>

long int sum(long int n,long int k);

int main(){
    long int t,nsum; 
    scanf("%ld",&t);
    for(int a0 = 0; a0 < t; a0++){
        long int num; 
        scanf("%ld",&num);
        num--;
        nsum = sum(num,3) + sum(num,5) - sum(num,15);
        printf("%ld\n",nsum);
    }
    return 0;
}

long int sum(long int n,long int k)
{
    long int d = (n / k);
    return (k * ((d * (d + 1) / 2)));
}
