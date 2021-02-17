#ifndef FINDCOMMON_LIBRARY_H
#define FINDCOMMON_LIBRARY_H

#define MAX 100

typedef int err_t;

void fillResult(int *result, int list[]);

err_t findCommon(int *list1, int numElem1, int *list2, int numElem2, int *result, int resultSize){
    static err_t counter = 0;

    for (int x = 0; x < numElem1; x++){
        for (int y = 0; y < numElem2; y++){
            if (*(list2+y) == *(list1+x)) {
                *(result+counter) = *(list1+x);
                counter++;
                break;
            }
        }
        if (counter == (resultSize-1)){
            break;
        }
    }

    return counter;
}

#endif
