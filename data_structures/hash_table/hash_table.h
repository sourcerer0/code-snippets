#ifndef HASH_TABLE_H
#define HASH_TABLE_H
#include <stdio.h>

//Número máximo de índices
//A tabela de símbolos possuirá cerca de 395 no máximo, para 5 objetos em cada índice
#define M 79

typedef char * string;

//Objetos presentes na tabela de símbolos
typedef struct {
    int key;
    string content;
} Pandora;

//Tabela de Símbolos por Hash Table
typedef struct table {
    Pandora object;
    struct table *next;
} *pandora_table;

int hashFunction(int key);

int setTable();

void STinsertion(Pandora object);

Pandora STsearch(int key);

string rand_string(int size);

Pandora createNewObject(string content, int key);

void printEntireTable();

#endif
