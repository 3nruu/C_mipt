#include <stdio.h>
#include <string.h>

void trim_after_first_space(char str[])
{
    int n = strlen(str);
    for (int i = 0; i <= n; i++)
    {
        if (str[i] == ' ')
        {
            str[i] = '\0';
        }
    }
}



int main()
{
char a[] = "Cats and Dogs";
printf("%s\n", a);

trim_after_first_space(a);

printf("%s\n", a); 

}