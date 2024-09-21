#include <stdio.h>

void reverse(int a[], int n) {
    int x;  
    int s = 0;
    int e = n - 1;

    while (s < e) {

        x = a[s];
        a[s] = a[e];
        a[e] = x;

        s++;
        e--;
    }
}



int main() {
    int a[1000];
    int n;
    

    scanf("%i", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%i", &a[i]);
    }

    reverse(a , n);
    for (int i = 0; i < n; ++i) {
        printf("%i ", a[i]);
    }

    return 0;
}
