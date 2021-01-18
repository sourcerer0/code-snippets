#include "string_split.h"
#include <stdio.h>

int main(){
    char text[100];
    char *separator =  "/";
    int length = 10;

    printf("Enter a string (separated by '/')\n>>");
    scanf("%s", &text);

    char **text_splitted = stringSplit(text, separator, &length);
    //char **text_splitted = SubStrings;

    int x = 0;
    do{
        printf("%s\n", text_splitted[x]);
        x++;
    } while (text_splitted[x] != NULL);
}
    