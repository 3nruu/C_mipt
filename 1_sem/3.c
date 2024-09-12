#include <stdio.h>

int main()
{
    int a;
    scanf("%d", &a);
     for (int i = 1; i <= a; i++) 
        
        printf("%3d -> %3d -> %3d\n", i, i*i, i*i*i);
    return 0;

}