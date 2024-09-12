#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    if (n == 0) {
        printf("None\n");
        return 0;
    }
    
    int prev, current;
    int increasing = 1, decreasing = 1, equal = 1;
    
    scanf("%d", &prev);
    
    for (int i = 1; i < n; ++i) {
        scanf("%d", &current);
        
        if (current > prev) 
        {
            decreasing = 0;
            equal = 0;
        }
        else if (current < prev) 
        {
            increasing = 0;
            equal = 0;
        }
            else 
        {
                increasing = 0;
                decreasing = 0;
        }
        
        prev = current;
    }
    
    if (equal) {
        printf("Equal\n");
    } else if (increasing) {
        printf("Increasing\n");
    } else if (decreasing) {
        printf("Decreasing\n");
    } else {
        printf("None\n");
    }
    
    return 0;
}
