#include <stdio.h>
#include <conio.h> //fot getch();
//#include <dos.h> //currently for getdate
#include <time.h>//its better
#include <stdbool.h> //for boolean operations
#include <Windows.h>//for color and system

#define pass (void)0

const float PI=3.1415929,GRAVITY=9.80665;
const int BIRTHYEAR = 1999;//struct date dt;
const char hexalpha[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
int i=0;

void printout(int);

void main()
{
    //CMD Initialising
    system("TITLE I'am C!");
    system("COLOR a");

    //Variable Declarations
    time_t _time = time(NULL);
    struct tm Today = *localtime(&_time);
    bool isProgrammingFun = true;
    bool isFishTasty = false;
    int M,x,y,z;//EDeclared an integer value
    int j=0;
    int age;//to be found
    float decimal=10.12;//declared a decimal value
    char string='c';//declared a character
    char Strings[10]="Hellow";//DEclared a string But error
    int matrix[3][3][3]={{{1,1,0},{0,1,0},{0,1,1}},
                         {{0,1,1},{0,0,1},{1,0,1}},
                         {{1,0,1},{1,0,0},{1,1,0}}};

    //Code Starts
    M=x=y=z=50;
    M+=50;//add 50with the value of m
    printf("Hello\tWorld\t!\n");// \t is for tab space
    printf("I\tam\tLearning\tC\n"); //\n Is for new line
    printf("\"And\tit\tis\t\tAwesome\"");/*the comment can be two lines
                                           And still Rum Code without execution comments*/
    printf ("\nman =%d\ndecimal=%f\nCharacter = %c\nString = %s",(M+x+y+z),decimal,string,Strings);
    printf("\nValue of pi =\t%f\nEarth's Gravity =\t%f",PI,GRAVITY);
    printf("\n%d\t%d",true,(5>3));
    printf("\nSize of strings is %lu",sizeof(Strings));
    printf("\nis Fish Tasty? = %d",isFishTasty);
    //printf("\nTodays Date %d/%d/%d",dt.da_day,dt.da_mon,dt.da_year);
    age = (Today.tm_year+1900) - BIRTHYEAR;
    printf("\nAge is %d",age);
    if(age>18)
    {
        printf("\nVoting Eligible. Vote Carefully");
    }
    else if(age<10)
    {
        printf("\nkuchu kuchu kuchu");
    }
    else
    {
        printf("\nYou are not Eligible to Vote.. Try again next year :-)\n");
    }
    switch (Today.tm_wday)
    {
        case 1:
            printf("\nToday is Monday");
            break;
        case 2:
            printf("\nToday is Tuesday");
            break;
        case 3:
            printf("\nToday is Wednesday");
            break;
        case 4:
            printf("\nToday is Thursday");
            break;
        case 5:
            printf("\nToday is Friday");
            break;
        case 6:
            printf("\nToday is Saturday");
            break;
        case 7:
            printf("\nToday is Sunday");
            break;
        default:
            printf("\nHave a Great Day :-)");
    }
    (58>12) ? printf("\n58 is Greater that 12") : printf("\n12 is Greater than 58");//Ternary operator You Know
    while (i<5)
    {
        printf("\n**");
        i++;
    }
    for(i=0;i<10;i++)
    {
        for(j=i;j<10;j++)
        {
            if (j==i)
            {
                continue;
            }
            printf("*H*");
        }
        printf("\n");
    }
    printf("\nHex Alphas: ");
    for(i=0;i<sizeof(hexalpha);i++)
    {
        printf(" %c", hexalpha[i]);
    }
    printf("\nLED Tv Color Code\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(matrix[i][j][0])
            {
                printf("R");
            }
            if(matrix[i][j][1])
            {
                printf("G");
            }
            if(matrix[i][j][2])
            {
                printf("B");
            }
        }
        printf("\n");
    }
    printout(5);
    getch();
}

void printout(int x)
{
    for (i=0;i<x;i++)
    {
        printf("\nHello Look Here");
    }
}

// Learning OOP in C
typedef struct People {
    char* name;
    int age;
    // Function to set Name and Age of Person of People
    void (*set)(People_t *, int, char*);
    // Function to get Name of Person of People
    char* (*get)(People_t *);
}People_t;

// Function to set Name and Age of Person of People
void SetPerson(People_t* This, int _age, char* _name) {
    This->age = _age;
    This->name = _name;
}

// Function to get Name of Person of People
char* GetPerson(People_t* This) {
    return This->name;
}

int StructMain() {
    People_t Person1;
    Person1.set = SetPerson;
    Person1.get = GetPerson;
    Person1.set(&Person1, 18, "Muhammed");
    printf("%s", Person1.get(&Person1));
    return 0;
}

//The Encapsulation
//Modulation
//Abstarction
//Polymorphisn
//Method Passing
//
//While Implemetntinh the concets in C
// The Main Thing To Is the Malloc, Realloc,Calloc, Free
//
//
//
//
//
//
//
//
//
