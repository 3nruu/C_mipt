#include <stdio.h>

int main() {
    int a[1000] , sum[1000];
    int n , m;
    

    scanf("%i %i", &n , &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++){
            int k = m*i + j;
            scanf("%d", &a[k]);
        }
    }

    for (int j = 0; j < m; j++) {
        sum[j] = 0;

        for (int i = 0; i < n; i++){
            int k = m*i + j;
            sum[j] += a[k];
        }
    }

    

    for (int j = 0; j < m; j++) {
        printf("%d ", sum[j]);
    }
    printf("\n");

    return 0;
}
