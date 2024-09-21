#include <stdio.h>

#define MAX 100  


void transpose(int a[MAX][MAX], int n) 
{
    int x;
    for (int i = 0; i < n; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            x = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = x;
        }
    }
}


void print(int a[MAX][MAX], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            printf("%d ", a[i][j]); 
        }
        printf("\n");
    }
}

int main() 
{
    int n;
    int a[MAX][MAX];


    FILE *input_file = fopen("C:/Users/tanx0/Downloads/matA.txt", "r");

    fscanf(input_file, "%d", &n);


    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            fscanf(input_file, "%d", &a[i][j]);
        }
    }

    fclose(input_file);


    transpose(a, n);


    FILE *result_file = fopen("C:/C_homework/C_mipt/function/result.txt", "w");


    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            fprintf(result_file, "%d ", a[i][j]);  
        }
        fprintf(result_file, "\n");
    }

    fclose(result_file); 

    return 0;
}
