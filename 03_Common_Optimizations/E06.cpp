#include <cmath>
#include <vector>
#include "supp.cpp"

float eval_1(const std::vector<float> & a, float x);
float eval_2(const std::vector<float> & a, float x);

int main() {
    std::vector<float> a = {1.f,2.f,3.f};
    float x = 2.f;

    tryFunc(eval_1, a, x);
    tryFunc(eval_2, a, x);

}

// 0.0349496 s
float eval_1(const std::vector<float> & a, float x)
{
    float y;
    y = a[0];
    for(unsigned i = 1; i < a.size(); ++i)
    y = y + a[i] * pow(x,i);
    return y;
}

// 0.014514 s
float eval_2(const std::vector<float> & a, float x)
{
    float y;
    y = a[0];
    for(unsigned i = 1; i < a.size(); ++i){
        // this could be a function
        for (unsigned j = 0; j < i; ++j){
            x *= x;
        }
        y = y + a[i] * x;
    }
    return y;
}