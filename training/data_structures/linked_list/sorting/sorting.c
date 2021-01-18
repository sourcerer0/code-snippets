#include "sorting.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_RAND 20

void listPartition(SingleLinkedListOfIntsNode *head, int value){
    int counter = 0;

    SingleLinkedListOfIntsNode *tempNode;
    int max_iter = getLength(head);

    do {
        if (head->value >= value){
            goesToEnd(head, tempNode);
        }

        if (head->value >= value) { head = head; }
        else { head = head->next; }
        counter++;
    } while (counter < max_iter);

    counter = 0;
    do {
        if (head->value > value){
            goesToEnd(head, tempNode);
        }

        if (head->value > value) { head = head; }
        else { head = head->next; }
        counter++;
    } while (counter < max_iter);

    return;
}

void createHead(SingleLinkedListOfIntsNode *head, int value_first){
    if (head == NULL) {
        exit (EXIT_FAILURE);
    }

    head->value = value_first;
    head->next = NULL;
}

void appendNode(SingleLinkedListOfIntsNode *head, SingleLinkedListOfIntsNode *seq, int value){
    if (seq == NULL) {
        exit (EXIT_FAILURE);
    }
    do {
        if (head -> next == NULL){
            head -> next = seq;

            seq -> value = value;
            seq -> next = NULL;
            break;            
        }
        head = head-> next;
    } while (1);
}

void printList (SingleLinkedListOfIntsNode *head){
    do{
        //printf("%d %d\n", head->value, head->next);
        printf("%d\n", head->value);
        head = head->next;
    }while (head != NULL);
}

int getLength (SingleLinkedListOfIntsNode *head){
    int counter = 0;

    do{
        counter++;
        head = head->next;
    }while (head != NULL);

    return counter;
}

void goesToEnd(SingleLinkedListOfIntsNode *head, SingleLinkedListOfIntsNode *tempNode){
    int tempValue;
    tempNode = head;

    while (tempNode->next != NULL){
        tempValue = tempNode->value;
        tempNode->value = tempNode->next->value;
        tempNode->next->value = tempValue;

        tempNode = tempNode->next;
    }
}

int main(){
    SingleLinkedListOfIntsNode *node1, *seq;

    node1 = malloc(sizeof(SingleLinkedListOfIntsNode));
    createHead(node1, 12);

    int value;
    for (int x = 0; x < 10; x++){
        seq = malloc(sizeof(SingleLinkedListOfIntsNode));

        value = (rand() % MAX_RAND + 1); //random number different from 0
        appendNode(node1, seq, value);
    }

    listPartition(node1, 10);
    printList(node1);

    return 0;
}
