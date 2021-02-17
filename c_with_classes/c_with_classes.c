#include <stdio.h>
#include "c_with_classes.h"


int main(int argc, char *argv){
    Calculator rcal = reg__init(2.3543, 3.276);

    Sci_Calculator sci_cal = sci__init(2.3543, 3.276);
    Sci_Calculator sci_cal_2 = sci__init(3.3257, 7.7542);
    Sci_Calculator sci_cal_3 = sci__init(8.4634, 11.0987);
    printf("\n");

    //printf("Regular Calculator:\nAdd: %d\nSub: %d\n\n", rcal.add(rcal.x, rcal.y), rcal.sub(rcal.x, rcal.y));
    //printf("Scientific Calculator:\nAdd: %f\nSub: %f\n\n", sci_cal.add(sci_cal.x, sci_cal.y), sci_cal.sub(sci_cal.x, sci_cal.y));


    printf("Regular Calculator:\nAdd: %d\nSub: %d\n\n", rcal.add(rcal.x, rcal.y), rcal.sub(rcal.x, rcal.y));

    printf("Scientific Calculator %d:\nAdd: %f\nSub: %f\n\n", sci_cal.mark, sci_cal.add(sci_cal.x, sci_cal.y), sci_cal.sub(sci_cal.x, sci_cal.y));
    printf("Scientific Calculator %d:\nAdd: %f\nSub: %f\n\n", sci_cal_2.mark, sci_cal_2.add(sci_cal_2.x, sci_cal_2.y), sci_cal_2.sub(sci_cal_2.x, sci_cal_2.y));
    printf("Scientific Calculator %d:\nAdd: %f\nSub: %f\n\n", sci_cal_3.mark,  sci_cal_3.add(sci_cal_3.x, sci_cal_3.y), sci_cal_3.sub(sci_cal_3.x, sci_cal_3.y));

    return 0;
}

//INSPIRATION : https://ejrh.wordpress.com/2012/01/24/namespaces-in-c/
