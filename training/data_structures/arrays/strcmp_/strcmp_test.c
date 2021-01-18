#include <stdio.h>
#include <string.h>

int main(){
    char first_name[20], second_name[20];
    int compara;

    fgets(first_name, 20, stdin);
    fgets(second_name, 20, stdin);
    compara = strcmp(first_name, second_name);
    printf("%s\n%s\n%d",first_name,second_name,compara);
    //scanf & fgets
    //printf
    //getchar & putchar
}