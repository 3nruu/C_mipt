#include <stdio.h>


int main() 
{
    char a;
    scanf("%c", &a);

    
    a = (int)a;

    if (a>=65 & a <=90 || a>97 & a <=122)
    {
        printf("Letter");
    }
    else if (a>=48 & a <=57)
    {
        printf("Digit");
    }
    else
    {
        printf("Other");
    }


    return 0;
}
