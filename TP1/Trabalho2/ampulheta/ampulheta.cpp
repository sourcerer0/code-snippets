#include <stdio.h>

using namespace std;

int main(int argv, char *argc[]){
    char word[100];
    printf(">>");
    fgets(word, 100, stdin);
    //scanf("%s", &word); #Não recebe palavras compostas

    //GET LENGTH
    char *ptr_to_word = word;
    int len = 0;
    do {
        len++;
        ptr_to_word++;
    }
    while (*ptr_to_word != '\0');

    //CHECKS WORD'S SIZE
    len -= 1;
    //printf("%d", len);
    if (len <= 0 || len > 100 || len % 2 == 0){
        printf("Comprimento da cadeia deve ser um numero impar maior que zero e menor que cem!\n");
        return 0;
    }
    int mid = len/2, lim = (len-mid-1);


    //DECREASE OUTPUT
    for (int x = 0; x < len - lim; x++){
        for (int y = 0; y < mid - (mid-x); y++){ printf(" "); }

        for (int y = x; y < mid; y++){ printf("%c", word[y]); }
        printf("%c", word[mid]);

        for (int y = mid + 1; y < len - x; y++){ printf("%c", word[y]); }
        printf("\n");
    }

    //INCREASE OUTPUT
    for (int x = 1; x < len - lim; x++){
        for (int y = 0; y < mid - x; y++){ printf(" "); }

        for (int y = mid - x; y < mid; y++){ printf("%c", word[y]); }
        printf("%c", word[mid]);

        for (int y = mid + 1; y <= mid + x; y++){ printf("%c", word[y]); }
        printf("\n");
    }

    return 0;
}
