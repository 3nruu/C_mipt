#include <stdio.h>
#include <stdlib.h>

struct node
{
int value;
struct node* next;
struct node* prev;
};
typedef struct node Node;


struct list
{
Node* head;
Node* tail;
size_t size;
};
typedef struct list List;

List init(size_t n)
{
    List list;

    list.head = NULL;
    list.tail = NULL;
    list.size = 0;

    if (n == 0)
    {
        return list;
    }

    Node* start = (Node*)malloc(sizeof(Node));

    start->value = 0;
    start->next = NULL;
    start->prev = NULL;

    list.head = start;
    list.tail = start;
    list.size = 1;


    for (size_t i = 1; i < n; i++)
    {
        Node* new = (Node*)malloc(sizeof(Node));

        new->value = 0;
        new->next = NULL;
        new->prev = start;
        start->next = new;
        start = new;
        list.tail = new;
        list.size++;
    }

    return list;
}

void print(const List* pl)
{
    Node* start = pl->head;

    for (size_t i = 0 ; i < pl->size; i++)
    {
        printf("%d ", start->value);
        start = start->next;
    }

    printf("\n");
}

void push_back(List* pl, int value)
 {
    Node* new = (Node*)malloc(sizeof(Node));
    new->value = value;
    new->prev = pl->tail;
    new->next = NULL;

    if (pl->size == 0) 
    {
        pl->head = new;
        pl->tail = new;
    } 

    else 
    {
        pl->tail->next = new;
        pl->tail = new;
    }

    pl->size++;

 }

int pop_back(List* pl)
{
    Node* last = pl->tail;
    int last_v = last->value;

    if (pl->size == 1)
    {
        pl->head = NULL;
        pl->tail = NULL;
    } 

    else 
    {
        pl->tail = last->prev;
        pl->tail->next = NULL;
    }

    free(last);
    pl->size--;

    return last_v;
}

void push_front(List* pl, int value)
{
    Node* new = (Node*)malloc(sizeof(Node));

    new->value = value;
    new->next = pl->head;
    new->prev = NULL;

    if (pl->size == 0)
    {
        pl->head = new;
        pl->tail = new;
    }
    else
    {
        pl->head->prev = new;
        pl->head = new;
    }

    pl->size++;
}

int pop_front(List* pl)
{
    Node* first = pl->head;
    int first_v = first->value;

    if (pl->size == 1)
    {
        pl->head = NULL;
        pl->tail = NULL;
    } 

    else 
    {
        pl->head = first->next;
        pl->head->prev = NULL;
    }

    free(first);
    pl->size--;

    return first_v;
}

Node* erase(List* pl, Node* p)
{
    if (pl->size == 1)
    {
        pl->head = NULL;
        pl->tail = NULL;
        free(p);
        pl->size--;

        return NULL;
    }

    Node* next = p->next;

    if (p == pl->head)
    {
        pl->head = next;
        next->prev = NULL;
    }
    else if (p == pl->tail)
    {
        pl->tail = p->prev;
        pl->tail->next = NULL;

        next = NULL;
    }
    else
    {
        p->prev->next = next;
        next->prev = p->prev;
    }

    free(p);
    pl->size--;

    return next;
}

void splice(List* plist, Node* p, List* pother) 
{
    if (plist->size == 0) {
        plist->head = pother->head;
        plist->tail = pother->tail;
    } 
    else if (p == plist->head) 
    {
        pother->tail->next = plist->head;
        plist->head->prev = pother->tail;
        plist->head = pother->head;
    } 
    else 
    {
        Node* prevNode = p->prev;
        prevNode->next = pother->head;
        pother->head->prev = prevNode;
        pother->tail->next = p;
        p->prev = pother->tail;
    }

    plist->size += pother->size;

    pother->head = NULL;
    pother->tail = NULL;
    pother->size = 0;
}

void destroy(List* pl) 
{
    Node* cur = pl->head;
    
    while (cur) 
    {
        Node* next = cur->next;
        free(cur);
        cur = next;
    }

    pl->head = NULL;
    pl->tail = NULL;
    pl->size = 0;
}

void advance(Node** pp, size_t n) 
{
    Node* cur = *pp;

    for (size_t i = 0; i < n && cur != NULL; ++i) 
    {
        cur = cur->next;
    }

    *pp = cur;
}

