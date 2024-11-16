#include <stdio.h>
#include <stdlib.h>

struct game
{
char title[50];
float rating;
};

typedef struct game Game;

void print_game(Game m) {
    printf("%s, " , m.title);
    printf("%f\n" , m.rating);
}

int cmp(const void *a, const void *b) 
{
    Game *g1 = (Game *)a;
    Game *g2 = (Game *)b;
    if (g1->rating < g2->rating) return 1;
    if (g1->rating > g2->rating) return -1;
    return 0;
}

int main()
{
    int n = 0;
    char title[50] , temp;
    scanf("%d", &n);
    Game garray[n];
    printf("ptr %d", n);

    for (int i = 0 ; i < n - 1  ; i++)
    {
        printf("start for..\n");
        scanf("%[^:]", &garray[i].title);
        scanf("%c", &temp);
        float sum = 0;
        int count = 0;
        int result = 0;
        int val = 0;
        while (1) 
        {
            scanf("%c", &temp);
            result = scanf("%i", &val);
            if (result != 1) 
            {
                break; 
            }
            sum += val;
            count++;
        }
        garray[i].rating = sum / count;
    }

    qsort(garray, n, sizeof(Game), cmp);

    for (int i = 0; i < n; i++) 
    {
        print_game(garray[i]);
    }


    return 0;
}