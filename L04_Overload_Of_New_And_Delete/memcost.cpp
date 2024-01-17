#include <iostream>
#include <memory>
#include "Utils.cpp"

const int N = 10000;

void memcost1();
void memcost2();
void memcost3();
void memcost4();

struct Prueba {
    float f1, f2;
    int i1, i2, i3;
};

int main() {
    std::cout << "Memoria estatica: ";
    tryFunc(memcost1);
    std::cout << "Memoria dinamica: ";
    tryFunc(memcost2);
    std::cout << "Unique Ptr: ";
    tryFunc(memcost3);
    std::cout << "Shared Ptr: ";
    tryFunc(memcost4);
}

/**********************************************************************/ /**
*
*  Function that tests the efficiency of static memory
*
*/
/**********************************************************************/
void memcost1() {
    Prueba p[N];
    
    for (int i = 0; i < N; ++i){
        p[i].i1 = i;
    }

    volatile int suma = 0;
    for (int i = 0; i < N; ++i) {
        suma += p[i].i1;
    }
}

/**********************************************************************/ /**
*
*  Function that tests the efficiency of dynamic memory
*
*/
/**********************************************************************/
void memcost2() {
    Prueba *p[N];

    for (int i = 0; i < N; ++i){
        p[i] = new Prueba;
        p[i]->i1 = i;
    }

    volatile int suma = 0;
    for (int i = 0; i < N; ++i) {
        suma += p[i]->i1;
        delete p[i];
    }
}

/**********************************************************************/ /**
*
*  Function that tests the efficiency of using unique pointers
*
*/
/**********************************************************************/
void memcost3() {
    std::unique_ptr<Prueba> p[N];

    for (int i = 0; i < N; ++i){
        p[i].reset(new Prueba);
        p[i]->i1 = i;
    }

    volatile int suma = 0;
    for (int i = 0; i < N; ++i) {
        suma += p[i]->i1;
    }
}

/**********************************************************************/ /**
*
*  Function that tests the efficiency of using shared pointers
*
*/
/**********************************************************************/
void memcost4() {
    // the same as memcost3 but with shared_ptr
    std::shared_ptr<Prueba> p[N];

    for (int i = 0; i < N; ++i){
        p[i].reset(new Prueba);
        p[i]->i1 = i;
    }

    volatile int suma = 0;
    for (int i = 0; i < N; ++i) {
        suma += p[i]->i1;
    }
}