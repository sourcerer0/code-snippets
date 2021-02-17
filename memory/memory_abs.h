#ifndef ADV_LIBRARY_H
#define ADV_LIBRARY_H

#define ADDR_BITS 10
#define MEMORY_SIZE pow(2, ADDR_BITS)

typedef struct {
    unsigned int used: 1;
    int content: 8;
    unsigned int address: ADDR_BITS;
} MEMO;

//Initialize memory and sets all addresses to 'unused'
MEMO *createMemory();

//Insert content into memory addressvv
int insertContentByAddress(MEMO *memory, int data, int addr);

//Clean address' content
int cleanAddressContent(MEMO *memory, int data, int addr);

#endif
