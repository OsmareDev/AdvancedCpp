#include <vector>

/*
5. Given the following recursive function:
*/

float f(const std::vector<float> & v, unsigned i) {
    float p;
    if (i == v.size() )
        p = 2;
    else {
        p = f(v, i+1);
        p = p * v[i];
    }

    return p;
}

/*
a) Transform the previous function to a tail recursive function (f1) using the method of
unfold/fold transformation. Write all the intermediate calculations.
*/

float f1(const std::vector<float> & v, unsigned i, float w) {
    if (i == v.size())
        return w;
    else
        return f1(v, ++i, v[i]*w);
}


/*
b) Write a function (f2) that calculates the same result as f doing a call to f1 with the
appropriate parameters.
*/

float f2(const std::vector<float> & v) {
    return f1(v, 0, 2);
}

/*
c) Transform the previous functions (f1 + f2) to an iterative function (f3).
*/

float f3(const std::vector<float> & v) {
    float aux = 2;
    for (unsigned i = 0; i < v.size(); ++i) 
        aux = aux * v[i];

    return aux;
}