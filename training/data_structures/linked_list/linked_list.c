#include "linked_list.h"
#include <stdio.h>

#define MAX 20

Stack *stackNew (void){
    static Stack *node1;

    node1 = malloc(sizeof(Stack));
    if (node1 == NULL) {
        exit (EXIT_FAILURE);
    }

    node1->next = NULL;

    return node1;
}

void stackFree (Stack *p){
    Stack *temp, *next;

    while (p != NULL){
        next = p->next;
        temp = p;

        p->next = NULL;
        p = next;
        free(temp);
    }

    free(p);
}

void stackPush (Stack *p, int elem){
    static Stack *top;

    top = malloc(sizeof(Stack));
    if (top == NULL) { exit(EXIT_FAILURE); }

    do {
        if (p -> next == NULL){
            p -> next = top;
            top->next = NULL;

            top->value = elem;
            return;
        }
        p = p->next;
    } while (1);
}

int stackPop (Stack *p){
    int value;
    Stack *nextNode = p->next;

    do {
        if (nextNode -> next == NULL){
            p->next = NULL;
            value = nextNode->value;

            free(nextNode);
            return value;
        }
        p = p->next;
        nextNode = nextNode->next;
    } while (1);
}

int stackEmpty (Stack *p){
    int counter = 0;

    do{
        Stack *next_node = p->next;
        if (next_node == NULL && counter == 0){ return 1; }
        counter++;
    }while (p != NULL);

    return 0;
}

void stackRemoveEven (Stack *p){
    Stack *nextNode, *tempNode;

    nextNode = p->next;
    do {
        tempNode = nextNode -> next;
        if (nextNode -> value % 2 == 0){
            p->next = tempNode;
            nextNode -> next = NULL;
            free(nextNode);
        }
        else {
            p = p->next;
        }

        nextNode = tempNode;
    } while (tempNode != NULL);
}

void printList (Stack *head){
    do{
        if (head->value == 0) {
            head = head->next;
            continue;
        }
        printf("%d\n", head->value);
        head = head->next;
    }while (head != NULL);
}

int main(){
    Stack *head = stackNew();
    int rand_number;

    for (int x = 0; x < MAX; x++){
        rand_number = (rand() % 100) + 1;
        stackPush(head, rand_number);
    }
    printf("ORIGINAL\n");
    printList(head);

    printf("\nNO EVEN NUMBERS\n");
    stackRemoveEven(head);
    printList(head);

    //free(head);
    stackFree(head);
    if (stackEmpty(head) != 1){ printList(head); }
    return 0;
}
