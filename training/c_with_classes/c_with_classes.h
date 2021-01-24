#ifndef CLASSES_H
#define CLASSES_H


// REGULAR CALCULATOR
typedef struct {
    int x, y;
    int (*add) (int, int);
    int (*sub) (int, int);
} Calculator;

int reg__add(int x, int y){ return x+y; }
int reg__sub(int x, int y){ return x-y; }
Calculator reg__init(int x, int y){
    static Calculator obj;

    obj.x = x;
    obj.y = y;
    obj.add = &reg__add;
    obj.sub = &reg__sub;

    return obj;
}
///////////////////////////////////////////////////////////



//SCIENTIFIC CALCULATOR
typedef struct {
    int x, y;
    float (*add) (float, float);
    float (*sub) (float, float);
} Sci_Calculator;

float sci__add(float x, float y){ return x+y; }
float sci__sub(float x, float y){ return x-y; }
Sci_Calculator sci__init(int x, int y){
    static Sci_Calculator obj;

    obj.x = x;
    obj.y = y;
    obj.add = &sci__add;
    obj.sub = &sci__sub;

    return obj;
}
///////////////////////////////////////////////////////////


#endif
