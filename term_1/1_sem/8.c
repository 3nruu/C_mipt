#include <stdio.h>

int main() 
{
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);

    int s = a;
    if (s % c != 0) 
    {
        s += c - (s % c);
    }

    for (int i = s; i <= b; i += c) 
    {
        printf("%d ", i);
    }
    
    return 0;
}
