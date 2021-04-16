#include <stdio.h>
#include <ctype.h>

using namespace std;

int main(){
    int A = 0, B = 0, C = 0;
    int A_M = 0, A_T = 0, A_N = 0, B_M = 0, B_T = 0, B_N = 0, C_M = 0, C_T = 0, C_N = 0;
    int moradores;
    char char_elevador, char_periodo;

    printf("Moradores:\n>>");
    scanf("%d", &moradores);
    if (moradores < 0) { printf("Número de moradores deve ser maior que zero!"); return 0;}

    printf("Responda a enquete a seguir de acordo com o elevador de sua preferência (A, B ou C)\n");
    printf("E, após, o período mais utilizado entre:\n• M = manhã\n• T = tarde\n• N = noite\n\n");
    for (int x = 1; x <= moradores; x++){
        printf("Morador %d\n", x);

        scanf("%c", &char_elevador);
        char_elevador = getchar();
        char_elevador = toupper(char_elevador);

        if (char_elevador == 'A'){
            A++;

            scanf("%c", &char_periodo);
            char_periodo = getchar();
            char_periodo = toupper(char_periodo);

            if (char_periodo == 'M'){ A_M++; }
            else if (char_periodo == 'T'){ A_T++; }
            else if (char_periodo == 'N'){ A_N++; }
        }
        else if (char_elevador == 'B'){
            B++;

            scanf("%c", &char_periodo);
            char_periodo = getchar();
            char_periodo = toupper(char_periodo);

            if (char_periodo == 'M'){B_M++;}
            else if (char_periodo == 'T'){B_T++;}
            else if (char_periodo == 'N'){B_N++;}
        }
        else if (char_elevador == 'C'){
            C++;

            scanf("%c", &char_periodo);
            char_periodo = getchar();
            char_periodo = toupper(char_periodo);

            if (char_periodo == 'M'){C_M++;}
            else if (char_periodo == 'T'){C_T++;}
            else if (char_periodo == 'N'){C_N++;}
        }
    }

    if (A > B && A > C){ 
        printf("\nElevador mais utilizado: A ");
        if (A_M > A_T && A_M > A_N){ printf("(de manhã)\n"); }
        else if (A_M < A_T && A_M < A_N || A_M < A_T && A_M < A_N && A_T > A_N){ printf("(à tarde)"); }
        else if (A_M > A_T && A_M < A_N || A_M < A_T && A_M < A_N && A_T < A_N || A_M == A_T && A_M < A_N){ printf("(de noite)"); }
        else if (A_M == A_T && A_M > A_N){ printf("(manhã e tarde)");}
        else if (A_M < A_T && A_T == A_N){ printf("(tarde e noite)");}
        else if (A_M > A_T && A_M == A_N){ printf("(manhã e noite)");}
        else if (A_M == A_T && A_M == A_N){ printf("(períodos iguais)");}
    }
    else if (A < B && A < C || A < B && A < C && B > C){
        printf("\nElevador mais utilizado: B ");
        if (B_M > B_T && B_M > B_N){ printf("(de manhã)\n"); }
        else if (B_M < B_T && B_M < B_N || B_M < B_T && B_M < B_N && B_T > B_N){ printf("(à tarde)"); }
        else if (B_M > B_T && B_M < B_N || B_M < B_T && B_M < B_N && B_T < B_N || B_M == B_T && B_M < B_N){ printf("(de noite)"); }
        else if (B_M == B_T && B_M > B_N){ printf("(manhã e tarde)");}
        else if (B_M < B_T && B_T == B_N){ printf("(tarde e noite)");}
        else if (B_M > B_T && B_M == B_N){ printf("(manhã e noite)");}
        else if (B_M == B_T && B_M == B_N){ printf("(períodos iguais)");}
    }
    else if (A > B && A < C || A < B && A < C && B < C || A == B && A < C){
        printf("\nElevador mais utilizado: C ");
        if (C_M > C_T && C_M > C_N){ printf("(de manhã)\n"); }
        else if (C_M < C_T && C_M < C_N || C_M < C_T && C_M < C_N && C_T > C_N){ printf("(à tarde)"); }
        else if (C_M > C_T && C_M < C_N || C_M < C_T && C_M < C_N && C_T < C_N || C_M == C_T && C_M < C_N){ printf("(de noite)"); }
        else if (C_M == C_T && C_M > C_N){ printf("(manhã e tarde)");}
        else if (C_M < C_T && C_T == C_N){ printf("(tarde e noite)");}
        else if (C_M > C_T && C_M == C_N){ printf("(manhã e noite)");}
        else if (C_M == C_T && C_M == C_N){ printf("(períodos iguais)");}
    }
    else if (A == B && A > C){
        printf("\nElevadores mais utilizados: A e B ");
    }
    else if (A < B && B == C){
        printf("\nElevadores mais utilizados: B e C ");
    }
    else if (A > B && A == C){
        printf("\nElevadores mais utilizados: A e C ");
    }
    else if (A == B && A == C){
        printf("\nDemanda pelos elevadores é igual ");
    }

    int manha = (A_M+B_M+C_M);
    int tarde = (A_T+B_T+C_T);
    int noite = (A_N+B_N+C_N);
    if (manha > tarde && manha > noite){ printf("\nPeríodo com maior demanda: Manhã\n"); }
    else if (manha < tarde && manha < noite || manha < tarde && manha < noite && tarde > noite){ printf("\nPeríodo com maior demanda: Tarde\n"); }
    else if (manha > tarde && manha < noite || manha < tarde && manha < noite && tarde < noite || manha == tarde && manha < noite){ printf("\nPeríodo com maior demanda: Noite\n"); }
    else if (manha == tarde && manha > noite){ printf("\nPeríodos de maior demanda: Manhã e Tarde\n");}
    else if (manha < tarde && tarde == noite){ printf("\nPeríodos de maior demanda: Tarde e Noite\n");}
    else if (manha > tarde && manha == noite){ printf("\nPeríodos de maior demanda: Manhã e Noite\n");}
    else if (manha == tarde && manha == noite){ printf("\nDemanda por período é igual\n");}
}