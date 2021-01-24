#include <stdio.h>
#include "c_with_classes.h"


int main(int argc, char *argv){
    Calculator rcal = reg__init(2.3543, 3.276);

    Sci_Calculator sci_cal = sci__init(2.3543, 3.276);

    printf("Regular Calculator: %d\n", rcal.add(rcal.x, rcal.y));
    printf("Scientific Calculator: %f\n", sci_cal.add(sci_cal.x, sci_cal.y));

    return 0;
}
