#include "string_inversion.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char *word;
    word = malloc(SIZE);

    printf("Enter a word (or sentence):");
    fgets(word, SIZE, stdin);
    int len = strlen(word);
    word = realloc(word, len);

    char * NewString = StringInversion(word, len);
    free(word);
    printf("%s\n", NewString);
    //printf("%d", strlen(NewString));

    return 0;
}