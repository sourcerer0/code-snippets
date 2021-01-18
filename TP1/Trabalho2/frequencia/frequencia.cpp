#include <stdio.h>

using namespace std;

int main(int argv, char* argc[]){
    int n, m, counter;;
    printf("Valor de N\n>>");
    scanf("%d", &n);

    printf("Valor de M\n>>");
    scanf("%d", &m);
    if (n < 2 || m < 2){
        printf("Valores para 'N' e 'M' devem ser maiores que 2!\n");
        return 0;
    }


    int matrix[n][m];
    int temp_val;
    printf("Entre com valores - de 0 a 9 - para compor a matriz:\n");
    for (int x = 0; x < n; x++){
        for (int y = 0; y < m; y++){
            while (1){
                printf("MATRIX [%d] [%d] --> ", x, y);
                scanf("%d", &temp_val);
                if (temp_val < 0 || temp_val > 9){
                    printf("Valor deve ser entre 0 e 9!\n");
                    continue;
                }
                else { break; }
            }
            matrix[x][y] = temp_val;
        }
    }


    //CHECKS FREQUENCY
    for (int value = 0; value < 10; value++){
        counter = 0;
        for (int x = 0; x < n; x++){
            for (int y = 0; y < m; y++){
                if (matrix[x][y] == value) { counter++; }
            }
        }
        if (counter == 0) { continue; }
        printf("%d: %dx\n", value, counter);
    }

    return 0;
}
