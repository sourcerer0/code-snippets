#include "sudoku.h"

void createRandomMatrix(int matrix[9][9]){
    //create sudoku from random numbers
    for (int x=0; x < 9; x++){
        for (int y=0; y<9; y++){
            matrix[x][y] = (rand() % 9) + 1;
        }
    }
    //print
    for (int x=0; x < 9; x++){
        for (int y=0; y<9; y++){
            printf("%d ", matrix[x][y]);
        }
        printf("\n");
    }
}

void lineVerification(int matrix[9][9], int valid_result){
    int result = 0;

    for (int x=0; x < 9; x++){
        for (int y=0; y<9; y++){
            result += matrix[x][y];
        }
        //printf("%d\n", result);
        if (result != valid_result){ printf("\nNot a solution! At line %d\n", x+1); return;}
        result = 0;
    }
}

void columnVerification(int matrix[9][9], int valid_result){
    int result = 0;

    for (int y=0; y < 9; y++){
        for (int x=0; x<9; x++){
            result += matrix[x][y];
        }
        //printf("%d\n", result);
        if (result != valid_result){ printf("Not a solution! At column %d\n", y+1); return;}
        result = 0;
    }
}

void blockVerification(int matrix[9][9], int valid_result){
    int result = 0, block=0;
    int LIM_y = 3, LIM_x = 3;
    int INIT_y = 0, INIT_x = 0;

    do{
        block++;
        for (int x=INIT_x; x < LIM_x; x++){
            for (int y=INIT_y; y<LIM_y; y++){
                result += matrix[x][y];
            }
        }
        //printf("%d\n", result);
        if (result != valid_result){ printf("Not a solution! At block %d\n", block); return;}
        result = 0;

        if (block % 6){
            INIT_x = 0;
            LIM_x = 3;

            INIT_y = 6;
            LIM_y = 9;
        }
        else if (block % 3){
            INIT_x = 0;
            LIM_x = 3;

            INIT_y = 3;
            LIM_y = 6;
        }
        else{
            INIT_y += 3;
            LIM_y += 3;
        }
        INIT_x += 3;
        LIM_x += 3;

    } while (block <= 9);
}

int main(){
    int matrix[9][9];
    int valid_result = 45;

    createRandomMatrix(matrix);
    lineVerification(matrix, valid_result);
    columnVerification(matrix, valid_result);
    blockVerification(matrix, valid_result);

    return 0;
}
