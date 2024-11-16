#include <stdio.h>
#include <string.h>

int main() 
{
    char a[100] , b[100];
    scanf("%s %s", a , b);
    int Na = strlen(a); 
    int Nb = strlen(b);

    int i = 0;
    while (i < Na || i < Nb) 
    {
        if (i < Na) 
        {
            printf("%c", a[i]);
        }
        if (i < Nb) 
        {
            printf("%c", b[i]);
        }
        i++;
    }

    
    return 0;

}
