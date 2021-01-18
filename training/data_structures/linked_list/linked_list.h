#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef LINKEDLIST_LIBRARY_H
#define LINKEDLIST_LIBRARY_H

typedef struct stack{
    int value;
    struct stack *next;
} Stack;

Stack *stackNew (void);

void stackFree (Stack *p);

void stackPush (Stack *p, int elem);

int stackPop (Stack *p);

//Returns 1 if list values are NULL, 0 if not
int stackEmpty (Stack *p);

//Removes nodes from list that contain even numbers
void stackRemoveEven (Stack *p);

//Prints every node from list starting from Stack *head
void printList (Stack *head);

#endif
