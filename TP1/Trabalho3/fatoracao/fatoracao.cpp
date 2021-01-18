#include <stdio.h>
#include <stdlib.h>

#define TARGET 10

using namespace std;

typedef long unsigned int Inteiro;

bool isPrime(Inteiro N){
    int x = 2;

    while (x < N){
        if (N % x == 0){
            return 0;
        }
        x++;
    }
    return 1;
}

bool isNegative(Inteiro n){
    if (n >= 0){ return false; }
    return true;
}

void printaFatoracao(int *vetor, Inteiro valor){
    int div_counter = 0;
    int divisor = vetor[0];

    printf("%lu -> ", valor);

    for (int x = 0; ; x++){
        if (vetor[x] != divisor){
            if (div_counter != 1){
                printf("%d ^ %d", divisor, div_counter);
            }
            else if (div_counter == 1){
                printf("%d", divisor);
            }
            if (vetor[x] == 0) { break; }
            div_counter = 1;
            printf(" x ");
        }
        else { div_counter++; }

        divisor = vetor[x];
    }
    printf("\n\n");
}

void fatora(Inteiro n){
    if (isPrime(n)){
        printf("Número primo!\n\n");
        return;
    }
    int inputN = n;

    int *divisores = (int *) malloc(sizeof(Inteiro) * TARGET);
    int counter = 0;

    for (int x = 2; n != 1; x++){
        if (isPrime(x)){
            while (n % x == 0) {
                if (x > TARGET){
                    divisores = (int *) realloc(divisores, (sizeof(Inteiro) * x) + 1);
                }
                n /= x;
                divisores[counter] = x;
                counter++;
            }
        }
        else { continue; }
    }

    printaFatoracao(divisores, inputN);
    return;
}

int main(int argv, char *argc[]){
    Inteiro inputN = 1;

    do{
        printf("Número (natural) >> ");
        scanf("%lu", &inputN);

        if (isNegative(inputN)){
            printf("Número deve ser positivo!\n");
            continue;
        }
        else if(!inputN){
            break;
        }

        fatora(inputN);
    } while(inputN != 0);

    return 0;
}
