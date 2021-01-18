#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

using namespace std;

#define MAX 100

char *list(char nome[]);
int countWords(char nome[]);
char* abrevia_nome(char nome[]);
int notName(char nome[], int pos);


int main(int argv, char *argc[]){
    char nome[MAX];

    do{
        printf("\nNOME >> ");
        fgets(nome, MAX, stdin);

        if (strcmp(nome, "\n") == 0) { return 0; }
        printf("%s\n", abrevia_nome(nome));
    } while (1);

    return 0;
}

char *list(char nome[]){
    char *abreviado = (char*) malloc(sizeof(char) * strlen(nome));

    for (int x = 0; x < strlen(nome) - 1; x++){
        abreviado[x] = nome[x];
    }

    return abreviado;
}

int countWords(char nome[]){
    int size = 0;

    for (int x = 0; x < strlen(nome) - 1; x++){
        if (nome[x] == *" " && nome[x+1] != *" "){ size++; }
    }
    return size+=1;
}

int notName(char nome[], int pos){
    if (nome[pos] != *" " && nome[pos+1] == *" "){
        return 1;
    }
    else if (nome[pos] == *"d" && nome[pos+1] != *" " && nome[pos+2] == *" "){
        return 1;
    }
    else if (nome[pos] == *"d" && nome[pos+1] != *" " && nome[pos+2] != *" " && nome[pos+3] == *" "){
        return 1;
    }
    return 0;
}

//Recebe uma cadeia de caracteres 'nome', com o nome
//completo do cliente, e retorna outra cadeia chamada 'abreviado'
char* abrevia_nome(char nome[]){
    char *abreviado = list(nome);
    char *string_list = list(nome);
    int number_of_words = countWords(nome);

    int counter = 0, word_counter = 1;
    int not_a_name = 0;

    for (int x = 0; x < strlen(nome); x++){
        //IGNORA MAIS DE UM ESPAÇO EM BRANCO
        if (string_list[x] == *" " && string_list[x + 1] == *" "){ continue; }

        //EXECUTA CASO TENHA CHEGADO AO INICIO DE OUTRA PALAVRA
        else if (string_list[x] == *" " && string_list[x+1] != *" "){
            word_counter++;

            //GRAVA ESPAÇO EM BRANCO
            if (not_a_name == 0){
                abreviado[counter] = toupper(string_list[x]);
                counter++;
            }

            //VERIFICA SE NÃO É CONECTIVO
            not_a_name = notName(nome, x+1);

            x++;
            if (word_counter < number_of_words && not_a_name == 0){
                //GRAVA PRIMEIRA LETRA
                abreviado[counter] = toupper(string_list[x]);
                counter++;

                //PULA PARA O FINAL DA PALAVRA
                while(string_list[x+1] != *" "){ x++; }
                continue;
            }
            else if (word_counter < number_of_words && not_a_name == 1){
                while(string_list[x+1] != *" "){ x++; }
                continue;
            }
        }
        abreviado[counter] = toupper(string_list[x]);
        counter++;
    }

    return abreviado;
}
