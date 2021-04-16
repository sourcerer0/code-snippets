#include <iostream>
#include "hello_world.h"

void hello_world(){
    #ifdef NDEBUG
    std::cout << "hello_world/0.1: Hello World Release!" <<std::endl;
    #else
    std::cout << "hello_world/0.1: Hello World Debug!" <<std::endl;
    #endif
}
