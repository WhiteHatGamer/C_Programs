#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdbool.h>
#include <Windows.h>

void main()
{
    float numbers[25] = {0},readN;
    int choice,pigeon_choice,trigonometry_choice,count,i,factorial=1;
    char temp;
    bool repetition,result_flag=false;
    double result = 0;
    while(true)
    {
    readN = 2;
    system("cls");
    printf("1. Sum\n2. Difference\n3. Product\n4. Quotient\n5. Remainder\n6. Permutaion\n7. Combination\n8. Pigeon Hole\n9. Root\n10. Power of\n11. Trigonometry\n12. Last Answer\n13. Quit\n##Operate with Identity/Invalid to break##");
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
                scanf("%f",&readN);
                numbers[count]=readN;
                count++;
            }
            for(i=0;i<count;i++)
            {
                result = result + numbers[i];
            }
            printf("Sum = %lf\n",result);
            result_flag=true;
            break;
        case 2:
            while (readN!=0)
            {
                printf("Enter Numbers: ");
                scanf("%f",&readN);
                numbers[count]=readN;
                count++;
            }
            result = numbers[0];
            for(i=1;i<count;i++)
            {
                result = result - numbers[i];
            }
            printf("Difference = %lf\n",result);
            result_flag=true;
            break;
        case 3:
            result = 1;
            while (readN!=1)
            {
                printf("Enter Numbers: ");
                scanf("%f",&readN);
                numbers[count]=readN;
                count++;
            }
            for(i=0;i<count;i++)
            {
                result = result * numbers[i];
            }
            printf("Product = %lf\n",(int)result);
            result_flag=true;
            break;
        case 4:
            while (readN!=1 || readN!=0)
            {
                printf("Enter Numbers: ");
                scanf("%f",&readN);
                numbers[count]=readN;
                count++;
            }
            result = numbers[0];
            for(i=1;i<count;i++)
            {
                result = result / numbers[i];
            }
            printf("Quotient = %lf\n",result);
            result_flag=true;
            break;
        case 5:
            while (readN!=0)
            {
                printf("Enter Numbers: ");
                scanf("%f",&readN);
                numbers[count]=(int)readN;
                count++;
            }
            result = numbers[0];
            for(i=0;i<count;i++)
            {
                result = (int)result % (int)numbers[i];
            }
            printf("Remainder = %d\n",(int)result);
            result_flag=true;
            break;
        case 6:
            printf("Enter Number of Elements: ");
            scanf("%f", &numbers[0]);
            printf("Enter Number of Slots: ");
            scanf("&f", &numbers[1]);
            printf("Repetition Allowed?(y/n) ");
            scanf("%c", &temp);//("y") ? repetition=true : ("n") ? repetition=false : printf("Invalid Choice\n"));
            result_flag=true;
            if (temp == 'y')
            {
                result = 1;
                for(i=0;i<numbers[1];i++)
                {
                    result=result*numbers[0];
                }
                printf("%dP%d(With Repetition) = %d",numbers[0],numbers[1],result);
                break;
            }
            else if (temp == 'n')
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
                printf("%dP%d = %lf",numbers[0],numbers[1],result);
                break;
            }
            else
            {
                printf("Wrong Choice...");
                break;
            }
        case 7:
            printf("Enter Total Number of Elements: ");
            scanf("%f", numbers[0]);
            printf("Enter Number of Selected objects: ");
            scanf("%f", numbers[1]);
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
            printf("%dC%d = %lf",numbers[0],numbers[1],result);
            result_flag=true;
            break;
        case 8:
            printf("1. Find Minimum Pigeons Required\n2. Find Pigeons3. Find Pigeon Holes\n Enter Your Choice");
            scanf("%d", pigeon_choice);
            result_flag=true;
            switch(pigeon_choice)
            {
                case 1:
                    printf("Enter Number of Pigeon holes: ");
                    scanf("%f", numbers[0]);
                    printf("Enter Number of Pigeons: ");
                    scanf("%f",numbers[1]);
                    result = ((numbers[0]*numbers[1])+1);
                    printf("Minimum Number of Pigeons Required is %d", result);
                    break;
                case 2:
                    printf("Enter Number of Pigeon holes: ");
                    scanf("%f", numbers[0]);
                    printf("Enter Minimum Pigeons Required: ");
                    scanf("%f",numbers[1]);
                    result = ((numbers[1]-1)/numbers[0]);
                    printf("Minimum Number of Pigeons Required is %d", result);
                    break;
                case 3:
                    printf("Enter Number of Pigeons: ");
                    scanf("%f", numbers[0]);
                    printf("Enter Minimum Pigeons Required: ");
                    scanf("%f",numbers[1]);
                    result = ((numbers[1]-1)/numbers[0]);
                    printf("Minimum Number of Pigeons Required is %d", result);
                    break;
            }
        case 9:
            printf("1. Square Root\n2. Cube Root\nEnter Your CHoice: ");
            scanf("%f",&numbers[0]);
            printf("Enter The Number: ");
            scanf("%f",&numbers[1]);
            if (numbers[0] == 1)
            {
                result = sqrt(numbers[1]);
            }
            else if (numbers[0] == 2)
            {
                result = cbrt(numbers[1]);
            }
            else
            {
                printf("Invalid Choice...");
            }
            printf("Result = %lf",result);
            result_flag=true;
            break;
        case 10:
            printf("Enter The Number: ");
            scanf("%f",&numbers[0]);
            printf("Enter Power: ");
            scanf("%f",&numbers[1]);
            result = pow(numbers[0],(int)numbers[1]);
            printf("%.2f^%d = %lf",numbers[0],(int)numbers[1],result);
            result_flag=true;
            break;
        case 11:
            printf("1. Sine\n2. Cosine\n3. Tangent\n4. Arcsine\n5. Arccosine\n6. Arctangent\nEnter Your Choice:");
            scanf("%d",&trigonometry_choice);
            printf("Enter Theta: ");
            scanf("%f",&numbers[0]);
            result_flag=true;
            switch(trigonometry_choice)
            {
                case 1:
                    printf("Sin(%f) = %lf",numbers[0],sin(numbers[0]));
                    break;
                case 2:
                    printf("Cos(%f) = %lf",numbers[0],cos(numbers[0]));
                    break;
                case 3:
                    printf("Tan(%f) = %lf",numbers[0],tan(numbers[0]));
                    break;
                case 4:
                    printf("Asin(fd) = %lf",numbers[0],asin(numbers[0]));
                    break;
                case 5:
                    printf("Acos(%f) = %lf",numbers[0],acos(numbers[0]));
                    break;
                case 6:
                    printf("Atan(%f) = %lf",numbers[0],atan(numbers[0]));
                    break;
                default:
                    printf("Invalid Choice");
                    break;
            }
            break;
        case 12:
            if (result_flag == false)
            {
                printf("No Operation Done Previously");
                break;
            }
            else
            {
                printf("Last Result is %lf",result);
            }
            break;
        case 13:
            return;
        default:
            printf("Try Again, Fail Again, Fail Better");
            break;
    }
    getch();
    }
}