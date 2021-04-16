#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define TAM_NOM 100
#define TAM_NOM_DEP 30

using namespace std;

typedef char Nome;
typedef float Salario;

typedef struct {
    Nome nome[TAM_NOM];
    Salario bruto;
    Nome departamento[TAM_NOM_DEP];
} Funcionario;

typedef struct {
    Nome departamento[TAM_NOM_DEP];
    unsigned int funcionarios = 0;
    Salario media = 0;
} Departamento;



void conversaoCaixaAlta(char vetor[]){
    for (size_t i = 0; i < strlen(vetor); i++) {
        if(vetor[i] >= 'a' && vetor[i] <= 'z') {
            vetor[i] = toupper(vetor[i]);
        }
    }
}

int getNumeroFuncionarios(){
    int num_funcionarios;

    printf("Número de Funcionários:\n");
    scanf("%d", &num_funcionarios);
    if (num_funcionarios <= 0){
        char confirma;

        printf("Assumindo número de funcionários como: %d\n Confirmar? (S/N)", (num_funcionarios - (num_funcionarios*2)));
        scanf(" %c", &confirma);
        //getchar();

        confirma = toupper(confirma);
        if (confirma == *"N"){
            printf("Novo número de Funcionários:\n");
            scanf("%d", &num_funcionarios);
        }
        else {
            num_funcionarios -= (num_funcionarios*2);
        }
    }

    return num_funcionarios;
}



Funcionario* le_cadastro(int num_funcionarios){
    Funcionario *funcionarios = (Funcionario*) malloc(sizeof(Funcionario) * (num_funcionarios + 1));

    for (int x = 0; x < num_funcionarios; x++){
        printf("\nDADOS DO FUNCIONÁRIO %d\n", (x+1));

        printf("Nome: ");
        getchar();
        fgets(funcionarios[x].nome, TAM_NOM, stdin);
        strtok(funcionarios[x].nome, "\n");
        conversaoCaixaAlta(funcionarios[x].nome);

        printf("Salario: ");
        scanf("%f", &funcionarios[x].bruto);

        printf("Departamento: ");
        getchar();
        fgets(funcionarios[x].departamento, TAM_NOM_DEP, stdin);
        strtok(funcionarios[x].departamento, "\n");
        conversaoCaixaAlta(funcionarios[x].departamento);
    }

    return funcionarios;
}

Departamento* monta_estatistica(Funcionario *funcionarios){
    int depSize = 1;
    Departamento *departamentos = (Departamento*) malloc(sizeof(Departamento) * (depSize + 1));

    char regist[TAM_NOM_DEP][TAM_NOM_DEP], depName[TAM_NOM_DEP];
    bool hit;

    for (int x = 0; strcmp("", funcionarios[x].nome) != 0; x++){
        strcpy(depName, funcionarios[x].departamento);
        hit = false;
        for (int y = 0; y < TAM_NOM_DEP; y++){ if (strcmp(depName, regist[y]) == 0) { hit = true; break; } }
        strcpy(regist[x], funcionarios[x].departamento);

        if (hit == false){
            strcpy(departamentos[depSize - 1].departamento, depName);
            for (int y = 0; strcmp("", funcionarios[y].nome) != 0; y++){
                if (strcmp(funcionarios[y].departamento, depName) == 0){
                    departamentos[depSize - 1].funcionarios++;
                    departamentos[depSize - 1].media += funcionarios[y].bruto;
                }
            }
            departamentos[depSize - 1].media /= departamentos[depSize - 1].funcionarios;
            depSize++;
        }
    }

    return departamentos;
}

void imprime_estatistica(Departamento *departamentos){
    printf("\n\n%s %30s %10s\n", "Departamento", "Qtd", "Média");
    printf("------------------------------------------------------\n");
    for (int x = 0; strcmp("", departamentos[x].departamento) != 0; x++){
        printf("%s %40d %10.2f\n", departamentos[x].departamento, departamentos[x].funcionarios, departamentos[x].media);
    }
}

int main(int argv, char *argc[]){
    int num_funcionarios = getNumeroFuncionarios();

    Funcionario *funcionarios = le_cadastro(num_funcionarios);
    Departamento *departamentos = monta_estatistica(funcionarios);
    imprime_estatistica(departamentos);

    return 0;
}
