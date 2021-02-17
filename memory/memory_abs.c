#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "memory_abs.h"

MEMO *createMemory(){
    static MEMO *memory;

    memory = malloc(MEMORY_SIZE * sizeof(MEMO));

    for (int addr = 0; addr < (MEMORY_SIZE - 1); addr++){
        memory[addr].address = addr;
        memory[addr].used = 0;
    }
    return memory;
}

int insertContentByAddress(MEMO *memory, int data, int addr){
    if (memory[addr].used == 0){
        memory[addr].used = 1;
        memory[addr].content = data;

        printf("CONTENT SUCESSFULLY ADDED!\n");
        return addr;
    }

    //No chance this works
    else {
        static int temp_addr = -1;
        temp_addr++;
        insertContentByAddress(memory, data, temp_addr);
    }
}

int cleanAddressContent(MEMO *memory, int data, int addr){
    if (addr >= MEMORY_SIZE || addr < 0){
        printf("INVALID MEMORY ADDRESS!\n");
    }
    else {
        if (memory[addr].used == 0){
            printf("ADDRESS ALREADY EMPTY!\n");
        }
        else{
            memory[addr].content = 0;
            memory[addr].used = 0;
            printf("SUCESSFULLY CLEARED!\n");
        }
    }
    return addr;
}

int main(int argv, char *argc[]){
    MEMO * const RAM = createMemory();
    int (*FUNC)(MEMO*, int, int);

    FUNC = insertContentByAddress;
    int addr = FUNC(RAM, 108, 45);
    addr = FUNC(RAM, 110, 45);

    FUNC = cleanAddressContent;
    FUNC(RAM, 0, 45);

    free(RAM);
    return 0;
}
