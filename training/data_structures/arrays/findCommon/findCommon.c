#include <stdio.h>
#include "findCommon.h"

int main(){
    int result[MAX];
    int list1[7] = {1, 76, 34, 87, 3, 6, 123};
    int list2[7] = {3, 5, 6, 23, 76, 12, 34};

    int *ptr_result = &result[0];
    int *ptr_list1 = &list1[0];
    int *ptr_list2= &list2[0];

    int listONEsize = 7, listTWOsize = 7;

    err_t len = findCommon(ptr_list1, listONEsize, ptr_list2, listTWOsize, ptr_result, MAX);

    for (int x = 0; x < len; x++){
        printf("%d\n", *(ptr_result+x));
    }

    return 0;
}

