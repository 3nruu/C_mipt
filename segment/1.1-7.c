#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
// 1  

int* p = (int*)malloc(sizeof(int));
*p = 123;
printf("%i\n", *p);
free(p);

// 2

char* a = (char*)malloc(sizeof(char) * 9);
strcpy(a, "Elephant");

printf("%s\n", a);
free(a);

// 3

char** b = (char**)malloc(sizeof(char*));
*b = (char*)malloc(sizeof(char) * 14);
strcpy(*b, "Cats and Dogs");

printf("%s\n", *b);
free(b);

// 4

struct book
{
char title[50];
int pages;
float price;
};
typedef struct book Book;

void print_book(Book b) {
printf("Book info:\n");
printf("Title: %s\nPages: %d\nPrice: %g\n\n", b.title, b.pages, b.price);
}

Book* c = (Book*)malloc(sizeof(Book));
strcpy(c->title, "Don Quixote");
c->pages = 1000;
c->price = 750.0;

print_book(*c);
free(c);

// 5

Book h = {"Don Quixote" , 1000 , 750.0};

Book** d = (Book**)malloc(sizeof(Book*));
*d = &h;

print_book(**d);
free(d);

//6

Book** e = (Book**)malloc(sizeof(Book*));

*e = (Book*)malloc(sizeof(Book));
strcpy((*e)->title, "Don Quixote");
(*e)->pages = 1000;
(*e)->price = 750.0;

print_book(**e);
free(e);

// 7 

Book* f = (Book*)malloc(sizeof(Book)*3);

strcpy(d[0]->title, "Don Quixote");
d[0]->pages = 1000;
d[0]->price = 750.0;

strcpy(d[1]->title, "Oblomov");
d[1]->pages = 400;
d[1]->price = 250.0;

strcpy(d[2]->title, "The Odessey");
d[2]->pages = 500;
d[2]->price = 500.0;

for (int i = 0 ; i <= 3 ; i++)
{
    print_book(*d[i]);
}

free(d);

}
