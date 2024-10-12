#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

struct book
{
char* title;
int pages;
float price;
};

typedef struct book Book;

void print_book(Book b) {
printf("Book info:\n");
printf("Title: %s\nPages: %d\nPrice: %g\n\n", b.title, b.pages, b.price);
}

// 8

Book* a = (Book*)malloc(sizeof(Book));

a->title = (char*)malloc(100 * sizeof(char));
strcpy(a->title, "Don Quixote");
a->pages = 1000;
a->price = 750.0;

//print_book(*a);
free(a);

// 9 

Book* b = (Book*)malloc(sizeof(Book) * 3);

b[0].title = (char*)malloc(100 * sizeof(char));
strcpy(b[0].title, "Don Quixote");
b[0].pages = 1000;
b[0].price = 750.0;

b[1].title = (char*)malloc(100 * sizeof(char));
strcpy(b[1].title, "Oblomov");
b[1].pages = 400;
b[1].price = 250.0;

b[2].title = (char*)malloc(100 * sizeof(char));
strcpy(b[2].title, "The Odessey");
b[2].pages = 500;
b[2].price = 500.0;

for (int i = 0 ; i <= 2 ; i++)
{
    print_book(b[i]);
}

free(b);

return 0;

}