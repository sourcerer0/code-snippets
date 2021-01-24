#include <stdio.h>
#include "c_with_classes.h"


int main(int argc, char *argv){
    Calculator rcal = reg__init(2.3543, 3.276);

    Sci_Calculator sci_cal = sci__init(2.3543, 3.276);

    printf("Regular Calculator:\nAdd: %d\nSub: %d\n\n", rcal.add(rcal.x, rcal.y), rcal.sub(rcal.x, rcal.y));
    printf("Scientific Calculator:\nAdd: %f\nSub: %f\n\n", sci_cal.add(sci_cal.x, sci_cal.y), sci_cal.sub(sci_cal.x, sci_cal.y));

    return 0;
}

//INSPIRATION : https://ejrh.wordpress.com/2012/01/24/namespaces-in-c/
