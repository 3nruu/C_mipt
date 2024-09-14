#include <stdio.h>

int main() {
    int a[1000];
    int n;
    

    scanf("%i", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%i", &a[i]);
    }

    int N = 2 * n;

    for (int i = n - 1; i >= 0; --i) {
        a[2 * i + 1] = a[i];
        a[2 * i] = a[i];
    }

    for (int i = 0; i < N; ++i) {
        printf("%i ", a[i]);
    }
    printf("\n");

    return 0;
}
