#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef SORTING_LIBRARY_H
#define SORTING_LIBRARY_H

#define MAX 100

typedef struct list {
    int value;
    struct list *next;
} SingleLinkedListOfIntsNode;

int getLength(SingleLinkedListOfIntsNode *head);
void goesToEnd(SingleLinkedListOfIntsNode *head, SingleLinkedListOfIntsNode *tempNode);

void listPartition(SingleLinkedListOfIntsNode *head, int value);

void createHead(SingleLinkedListOfIntsNode *head, int value_first);

void appendNode(SingleLinkedListOfIntsNode *head, SingleLinkedListOfIntsNode *seq, int value);

void printList (SingleLinkedListOfIntsNode *head);

int getLength (SingleLinkedListOfIntsNode *head);

void goesToEnd(SingleLinkedListOfIntsNode *head, SingleLinkedListOfIntsNode *tempNode);

#endif
