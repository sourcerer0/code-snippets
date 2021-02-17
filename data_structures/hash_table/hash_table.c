#include "hash_table.h"
#include <stdlib.h>
#include <stdio.h>

pandora_table *SymbolTable;

int hashFunction(int key){
    int hash_code;

    //this could be better
    hash_code = key % M;
    return hash_code;
}

int setTable(){
    int counter = 0;

    SymbolTable = malloc(M * sizeof(pandora_table));
    if (SymbolTable == NULL) { printf("Out of memory!"); EXIT_FAILURE; return 0; }
    for (int i=0; i < M; i++){
        counter++;
    }
    return counter;
}

void STinsertion(Pandora object){
    static pandora_table newNode;

    newNode = malloc(sizeof(pandora_table));
    if (newNode == NULL) { printf("Out of memory!"); EXIT_FAILURE; return; }

    int k = object.key;
    int hash_code = hashFunction(k);

    newNode->object = object;
    newNode->next = SymbolTable[hash_code];
    SymbolTable[hash_code] = newNode;
}

Pandora STsearch(int key){
    pandora_table temp;
    Pandora null_obj;
    null_obj.content = NULL;

    int hash_code = hashFunction(key);
    for (temp = SymbolTable[hash_code]; temp != NULL; temp = temp->next){
        if (temp->object.key == key){ return temp->object; }
    }
    return null_obj;
}

Pandora createNewObject(string content, int key){
    static Pandora obj;

    obj.key = key;
    obj.content = content;
    return obj;
}

string rand_string(int size){
    static string str;
    str = malloc(sizeof(char)*size+1);

    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.-#'?!";
    if (size) {
        for (size_t n = 0; n < size; n++) {
            int key = rand() % (int) (sizeof charset - 1);
            str[n] = charset[key];
        }
        str[size] = '\0';
    }
    return str;
}

void printEntireTable(){
    pandora_table temp;

    for (int x = 0; x < M; x++){
        for (temp = SymbolTable[x]; temp != NULL; temp = temp->next){
            Pandora temp_obj = temp->object;
            printf("%d: %s -> ", temp_obj.key, temp_obj.content);
        }
        printf("\n");
    }
}

int main(){
    setTable();

    for (int x=0; x < M * 4; x++){
        string str = rand_string(10);
        Pandora obj = createNewObject(str, x);

        STinsertion(obj);
    }

    printEntireTable();
    return 0;
}
