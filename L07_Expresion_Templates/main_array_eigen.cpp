#include <iostream>
#include <Eigen/Dense>
#include "expresion.h"
#include "sarray2.h"

const unsigned TAM = 1000000;
const unsigned ITERATION = 100;
const double val1 = 3.0;
const double val2 = 2.0;

int main()
{
    Eigen::ArrayXd x(TAM), y(TAM);
    std::cout << "**** TESTING EIGEN **** \n";


    for(unsigned i = 0; i < TAM; ++i)
    {
        x[i] = val1;
        y[i] = val2;
    }

    for(unsigned i = 0; i < ITERATION; ++i)
    {
        x = ((1.2 + x) * y + (2.0 * y).pow(2.0)) * x;
    }

    return 0;
}