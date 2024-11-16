#include <stdio.h>
#include <string.h>

int main() {
    int number = 12;
    int a[10] = {1 , 2 , 3 , 4 , 5};
    char str[10] = "111";
    int* p1 = &a[0];
    int* p2 = &a[3];
    //printf("%s\n", str); 
    

    printf("%ld\n", p2 - p1);  
  
    return 0;
}
