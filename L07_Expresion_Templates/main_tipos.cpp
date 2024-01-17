#include <iostream>
#include "expresion.h"
#include "sarray2.h"

const unsigned TAM = 1000000;

int main()
{

    Array<double> x(TAM), y(TAM);
    std::cout << "**** TYPES **** \n";

    std::cout << (1.2 * x + y).type() << '\n';

    return 0;
}