#include <stdio.h>
#include <conio.h>
#include <string.h>

void main()
{
    int t,i;
    scanf("%d",&t);
    int cases[t];
    for (int j=0;j<t;j++)
    {
        cases[j]=0;
    }
    for(i=0;i<t;i++)
    {
        int n = 0;
        int a[26] = {0};
        for(int j=0;j<26;j++)
        {
            scanf("%d",&a[j]);
        }
        scanf("%d",&n);
        char s1[n][10];
        int flag = 0;
        for (int j=0;j<n;j++)
        {
            char s[10]="";
            scanf("%s",&s);
            int k=0;
            char sum[10] = "";
            char c;
            do
            {
                c=s[k];
                int num = c - 'A';
                s1[j][k] = a[num];
                k++;
            } while (s[k] != '\0');
            for (int m = 0;m<j;m++)
            {
                if (!strcmp(s1[j],s1[m]))
                {
                    cases[i] = 1;
                }
            }
        }
    }
    for(i=0;i<t;i++)
    {
        if (cases[i])
        {
            printf("Case #%d: YES\n",i+1);
        }
        else
        {
            printf("Case #%d: NO\n",i+1);
        }
    }
    getch();
}