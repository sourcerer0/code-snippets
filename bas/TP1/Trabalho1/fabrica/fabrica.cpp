#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define funcionarios_totais 40
#define funcionarios_X 24
#define funcionarios_Y 32

#define lucro_linhaX(x, y) (x * y)
#define lucro_linhaY(x, y) (x * y)

typedef float lucro;
typedef int funcionarios;

struct stats{
    funcionarios linha_X;
    funcionarios linha_Y;
    lucro lucro_X;
    lucro lucro_Y;
    lucro lucro_total;
};

typedef struct fabrica{
    struct stats valores;
    struct fabrica *next;
} Fabrica;


Fabrica *createHead(void){
    static Fabrica *head;

    head = (Fabrica*) malloc(sizeof(Fabrica));
    if (head == NULL) {
        exit (EXIT_FAILURE);
    }

    head->next = NULL;
    return head;
}

void appendNode(Fabrica *head, lucro lucro_X, lucro lucro_Y, funcionarios linha_X, funcionarios linha_Y, lucro lucro_total){
    static Fabrica *top;

    top = (Fabrica*) malloc(sizeof(Fabrica));
    if (top == NULL) { exit(EXIT_FAILURE); }

    do{
        if (head -> next == NULL){
            head -> next = top;

            top->valores.linha_X = linha_X;
            top->valores.linha_Y = linha_Y;
            top->valores.lucro_X = lucro_X;
            top->valores.lucro_Y = lucro_Y;
            top->valores.lucro_total = lucro_total;

            top->next = NULL;
            break;
        }
        head = head->next;
    } while (1);
}

void getMaiorLucro(Fabrica *head){
    Fabrica *maiorLucro;

    do {
        //printf("%1.3f\n", head->valores.lucro_total);
        if (maiorLucro->valores.lucro_total < head->valores.lucro_total) { maiorLucro = head; }
        head = head->next;
    } while (head != NULL);

    printf("\nLinha padrão: %d funcionários - %1.2f de lucro\n", maiorLucro->valores.linha_X, maiorLucro->valores.lucro_X);
    printf("Linha de luxo: %d funcionários - %1.2f de lucro\n", maiorLucro->valores.linha_Y, maiorLucro->valores.lucro_Y);
    printf("Lucro total: %1.2f\n\n", maiorLucro->valores.lucro_total);
}

int main(){
    int comb = (funcionarios_totais - funcionarios_Y);
    lucro lucro_X, lucro_Y, lucro_total;

    funcionarios linha_X = comb, linha_Y = funcionarios_Y;
    Fabrica *head = createHead();

    printf("Lucro pretendido para linha padrão:\n>>");
    scanf("%f", &lucro_X);
    printf("Lucro pretendido para linha de luxo:\n>>");
    scanf("%f", &lucro_Y);

    //Testa variações possíveis de acordo com o número de funcionários na linha
    //e adiciona um Nó a lista
    do {
        lucro lucro_linhaX = lucro_linhaX(linha_X, lucro_X);
        lucro lucro_linhaY = lucro_linhaY(linha_Y/2, lucro_Y);
        lucro_total = lucro_linhaX + lucro_linhaY;
        appendNode(head, lucro_linhaX, lucro_linhaY, linha_X, linha_Y, lucro_total);

        linha_Y -= 1;
        linha_X += 1;
    } while (linha_X <= funcionarios_X);

    //Verifica a combinação com maior lucro e imprime valores
    getMaiorLucro(head);

    return 0;
}
