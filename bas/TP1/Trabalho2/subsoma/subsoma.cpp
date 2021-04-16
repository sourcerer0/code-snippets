#include <stdio.h>
#include <stdlib.h>

using namespace std;

/*
int retornaMaiorSomatorio(int *sequencia, int k, int init){
    int maior_soma = 0;

    for (int x = 0; x < k; x++){
        maior_soma += sequencia[init+x];
    }
    return maior_soma;
}
*/

int main(int argv, char *argc[]){
    int *seqL, iterN, valK;
    seqL = (int*)malloc(sizeof(int));

    printf("Quantidade de número a serem lidos:\n");
    scanf("%d", &iterN);
    if (iterN < 2){
        printf("\nDeve ser maior que 2!\n");
        return 0;
    }
    seqL = (int*)realloc(seqL, (iterN*sizeof(int)));


    printf("Números inteiros:\n");
    for (int x = 0; x < iterN; x++){
        scanf("%d", &seqL[x]);
    }
    printf("Feito!\nAgora, por favor, forneça o tamanho da subsequência a ser calculada!\n>>");
    scanf("%d", &valK);
    if (valK < 1 || valK > iterN){
        printf("\nValor inválido!\nDeve ser <= a quantidade de números inteiros e >= a 1\n");
        return 0;
    }


    int tempSomatorio = 0, subList[valK] = {0,0,0};
    int maiorSomatorio = tempSomatorio;

    for (int x = 0; x < (iterN - (valK-1)); x++){
        tempSomatorio = 0;
        for (int y = 0; y < valK; y++){ tempSomatorio += seqL[x+y]; }

        if (tempSomatorio > maiorSomatorio){
            maiorSomatorio = tempSomatorio;
            for (int y = 0; y < valK; y++){
                subList[y] = seqL[x+y];
            }
        }
    }


    printf("Subsequência de maior somatório:\n>");
    for (int i = 0; i < valK; i++){
        printf(" %d ", subList[i]);
    }
    printf("\nSomatório: %d\n", maiorSomatorio);

    free(seqL);
    return 0;
}

