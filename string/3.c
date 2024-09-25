#include <stdio.h>
#include <string.h>

int is_palindrome(char* a) 
{
    int n = strlen(a);

    
    for (int i = 0; i < n / 2; i++) 
    {
        if (a[i] != a[n - i - 1]) 
        { 
            return 0; 
        }
    }

    return 1;  
}

int main() 
{
    
    char a[100];
    scanf("%s", a);
    
    if (is_palindrome(a)) 
    {
        printf("Yes\n");
    } 
    
    else 
    {
        printf("No\n");
    }

    return 0;
}
