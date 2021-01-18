#include <string.h>
//#include <stdio.h>

#ifndef STRING_SPLIT_H
#define STRING_SPLIT_H

char** stringSplit (char *text, char *separator, int *length){
    char *token = strtok(text, separator);
    static char *SubStrings[100];
    int counter=0;

    do{
        //printf("%s\n", token);
        SubStrings[counter] = token;
        counter++;
        token = strtok(NULL, separator);

    } while (token != NULL);

    return SubStrings;
}

#endif

//Passing '//'
//**************
//Program received signal SIGSEGV, Segmentation fault.
//0x00007ffff7e83206 in ?? () from /lib/x86_64-linux-gnu/libc.so.6