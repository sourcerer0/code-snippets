#include "hash_table.h"
#include <stdio.h>
#include <stdlib.h>

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

int hashFunction(int key){
    int hash_code;

    //this could be better
    hash_code = key % M;
    return hash_code;
}

int main(){
    int hash_code = hashFunction(98);
    printf("%d", hash_code);

    return 0;
}
