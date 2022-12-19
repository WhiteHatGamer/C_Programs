#include <stdio.h>
#include<conio.h>
#include<stdbool.h>

void main()
{
    float numbers[25],readN=2;
    int choice,pigeon_choice,count,i,factorial=1;
    char temp;
    bool repetition;
    double result = NULL;
    printf("1. Sum\n2. Difference\n3. Product\n4. Quotient\n5. Remainder\n6. Permutaion\n7. Combination\n8. Pigeon Hole\n9. Last Answer\n##Operate with Identity/Invalid to break##");
    printf("\nOperation Mode: ");
    scanf("%d",&choice);
    count = 0;
    switch(choice)
    {
        case 1:
            result = 0;
            while (readN!=0)
            {
                printf("Enter Numbers: ");
                scanf("%d",&readN);
                numbers[count]=readN;
                count++;
            }
            for(i=0;i<count;i++)
            {
                result = result + numbers[i];
            }
            printf("Sum = %lf\n",result);
            break;
        case 2:
            while (readN!=0)
            {
                printf("Enter Numbers: ");
                scanf("%d",&readN);
                numbers[count]=readN;
                count++;
            }
            result = numbers[0];
            for(i=1;i<count;i++)
            {
                result = result - numbers[i];
            }
            printf("Difference = %lf\n",result);
            break;
        case 3:
            result = 1;
            while (readN!=1)
            {
                printf("Enter Numbers: ");
                scanf("%d",&readN);
                numbers[count]=readN;
                count++;
            }
            for(i=0;i<count;i++)
            {
                result = result * numbers[i];
            }
            printf("Product = %d\n",(int)result);
            break;
        case 4:
            while (readN!=1 || readN!=0)
            {
                printf("Enter Numbers: ");
                scanf("%d",&readN);
                numbers[count]=readN;
                count++;
            }
            result = numbers[0];
            for(i=1;i<count;i++)
            {
                result = result / numbers[i];
            }
            printf("Quotient = %lf\n",result);
            break;
        case 5:
            while (readN!=0)
            {
                printf("Enter Numbers: ");
                scanf("%d",&readN);
                numbers[count]=readN;
                count++;
            }
            result = numbers[0];
            for(i=0;i<count;i++)
            {
                result = (int)result % (int)numbers[i];
            }
            printf("Remainder = %d\n",(int)result);
            break;
        case 6:
            printf("Enter Number of Elements: ");
            scanf("%d", &numbers[0]);
            printf("Enter Number of Slots: ");
            scanf("&d", &numbers[1]);
            printf("Repetition Allowed?(y/n) ");
            scanf("%c", &temp);//("y") ? repetition=true : ("n") ? repetition=false : printf("Invalid Choice\n"));
            if (temp=="y")
            {
                result = 1;
                for(i=0;i<numbers[1];i++)
                {
                    result=result*numbers[0];
                }
                printf("%dP%d(With Repetition) = %d",numbers[0],numbers[1],result);
                break;
            }
            else if(temp=="n");
            {
                for(i=1;i<=numbers[0];i++)
                {
                    factorial=factorial*i;
                }
                result = factorial;
                factorial = 1;
                for(i=1;i<=numbers[1];i++)
                {
                    factorial=factorial*i;
                }
                result = result / factorial;
                printf("%dP%d = %d",numbers[0],numbers[1],result);
                break;
            }
            else
            {
                printf("Wrong Choice...");
                break;
            }
        case 7:
            printf("Enter Total Number of Elements: ");
            scanf("%d", Numbers[0]);
            printf("Enter Number of Selected objects")
            scanf("%d", Numbers[1]);
            factorial = 1;
            for(i=1;i<=numbers[0];i++)
                {
                    factorial=factorial*i;
                }
            result = factorial;
            factorial = 1;
            for(i=1;i<=numbers[1];i++)
                {
                    factorial=factorial*i;
                }
            result = result/factorial;
            factorial = 1;
            for(i=1;i<=(numbers[0]-numbers[1]);i++)
                {
                    factorial=factorial*i;
                }
            result = result * (1/factorial);
            printf("%dC%d = %d",numbers[0],numbers[1],result);
        case 8:
            printf("1. Find Minimum Pigeons Required\n2. Find Pigeons3. Find Pigeon Holes")
            scanf("%d", pigeon_choice);
            switch(pigeon_choice)
            {
                case 1:
                    printf("Enter Number of Pigeon holes: ");
                    scanf("%d", numbers[0]);
                    printf("Enter Number of Pigeons: ");
                    scanf("%d",numbers[1]);
                    result = ((numbers[0]*numbers[1])+1);
                    printf("Minimum Number of Pigeons Required is %d", result);
                    break;
                case 2:
                    printf("Enter Number of Pigeon holes: ");
                    scanf("%d", numbers[0]);
                    printf("Enter Minimum Pigeons Required: ");
                    scanf("%d",numbers[1]);
                    result = ((numbers[1]-1)/numbers[0]);
                    printf("Minimum Number of Pigeons Required is %d", result);
                    break;
                case 3:
                    printf("Enter Number of Pigeons: ");
                    scanf("%d", numbers[0]);
                    printf("Enter Minimum Pigeons Required: ");
                    scanf("%d",numbers[1]);
                    result = ((numbers[1]-1)/numbers[0]);
                    printf("Minimum Number of Pigeons Required is %d", result);
                    break;
            }
        case 9:
            if (result == NULL)
            {
                printf("No Operation Done Previously");
                break;
            }
            else
            {
                printf("Last Result is %lf",result);
            }
            break;
        default:
            printf("Try Again, Fail Again, Fail Better");
            break;
    }
    getch();
}