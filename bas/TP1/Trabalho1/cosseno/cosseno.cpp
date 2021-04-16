#include <stdio.h>
#include <math.h>

using namespace std;

typedef int parcelas;
typedef double graus;
typedef double cosseno;

//Função trigonométrica do cosseno seguindo a série de Maclaurin
int main(){
    long double exp;
    unsigned long long int fact;
    cosseno cos_X = 1;
    parcelas N;
    graus X;

    //Recebe graus e transforma em radianos
    printf("Graus:\n>>");
    scanf("%lf", &X);
    graus x_rad = X*M_PI/180;

    //Recebe parcelas
    printf("Parcelas:\n>>");
    scanf("%d", &N);
    if (N < 0){ N -= N*2; }

    for (int ITER = 1; ITER <= N; ITER++){
        exp = x_rad;
        fact = ITER*2;

        for (int i = 1; i < ITER*2; i++){
            exp *= x_rad;
            fact *= ITER*2 - i;
        }

        if (ITER%2 == 1){
            printf("- %llf / %llu\n", exp, fact);
            cos_X -= exp/fact;
        }
        else if (ITER%2 == 0){
            printf("+ %llf / %llu\n", exp, fact);
            cos_X += exp/fact;
        }
    }

    printf("\nCosseno de %1.3lf --> %1.3lf\n", X, cos_X);
    return 0;
}