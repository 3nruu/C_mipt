#include <stdio.h>
#include <string.h>

void encrypt(char* a, int k) {
    int n = strlen(a);

    for (int i = 0; i < n; i++) 
    {  
        if (a[i] >= 'A' && a[i] <= 'Z') 
        {  
            if (a[i] + k > 'Z') 
            {
                a[i] = a[i] + k - 26;  
            } 
            else 
            {
                a[i] += k; 
            }
        } 
        else if (a[i] >= 'a' && a[i] <= 'z') 
        {  
            if (a[i] + k > 'z') 
            {
                a[i] = a[i] + k - 26;  
            } 
            else 
            {
                a[i] += k; 
            }
        }
    }
}

int main() {
    char a[100];
    int k;


    scanf("%d %s", &k, a);
    
    encrypt(a, k);  
    
    printf("%s\n", a);  

    return 0;
}
