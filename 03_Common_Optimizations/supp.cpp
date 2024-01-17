/*
* Functions for Testing the loops
*/

#include "crono.cpp"
#include <vector>

const int n_loop = 100000;

// ejercicio 1
void tryFunc(bool(*func)(const int&), const int& n) {
    Cronometro c;

    for (int i = 0; i < n_loop; i++) {
        func(n);
    }
}
void tryFunc(bool(*func)(int), const int& n) {
    Cronometro c;

    for (int i = 0; i < n_loop; i++) {
        func(n);
    }
}

// ejercicio 2
void tryFunc(unsigned(*func)(const unsigned&), const unsigned& n) {
    Cronometro c;

    for (int i = 0; i < n_loop; i++) {
        func(n);
    }
}

void tryFunc(unsigned(*func)(unsigned), const unsigned& n) {
    Cronometro c;

    for (int i = 0; i < n_loop; i++) {
        func(n);
    }
}

// Ejercicio 5
void tryFunc(unsigned(*func)(std::vector<int>& v, int x), std::vector<int>& v, int x) {
    Cronometro c;

    for (int i = 0; i < n_loop; i++) {
        func(v, x);
    }
}

// Ejercicio 6
void tryFunc(float(*func)(const std::vector<float> & a, float x), const std::vector<float> & a, float x) {
    Cronometro c;

    for (int i = 0; i < n_loop; i++) {
        func(a, x);
    }
}

// Ejercicio 8
void tryFunc(void(*func)()) {
    Cronometro c;

    for (int i = 0; i < n_loop; i++) {
        func();
    }
}