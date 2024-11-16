#include <stdio.h>

void sortColumn(int matrix[][100], int n, int x) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (matrix[j][x] > matrix[j + 1][x]) {
                
                int temp = matrix[j][x];
                matrix[j][x] = matrix[j + 1][x];
                matrix[j + 1][x] = temp;
            }
        }
    }
}


int main() {
    int a[100][100];
    int n , m;
    

    scanf("%i %i", &n , &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++){
            
            scanf("%d", &a[i][j]);
        }
    }

    for (int j = 0; j < m; j++) {
        sortColumn(a , n , j);
    }
    
    

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}