#ifndef STRING_INVERSION_H
#define STRING_INVERSION_H

#include <stdio.h>
#define SIZE 100

//Escreva usando a linguagem C uma função para inverter uma string.
char * StringInversion(char * string_, int string_size){
    static char NewString[SIZE];

    for (int x = 0; x < string_size; x++){
        NewString[x] = ("%c", *(string_+((string_size-1)-x)));
    }
    return NewString;
}

#endif
