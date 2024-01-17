//1. Write several versions for checking if a number is even. Sort them from less efficient to more
//efficient. Repeat the exercise for checking if a number is divisible by 8.

#include <iostream>
#include "supp.cpp"

bool isEven_1(const int& a);
bool isEven_2(const int& a);
bool isEven_3(const int& a);
bool isEven_4(int a);
bool isEven_5(const int& a);
bool isDivisibleBy8_1(const int& a);
bool isDivisibleBy8_2(const int& a);
bool isDivisibleBy8_3(int a);

void tryFunc(bool(*func)(const int&), const int& n);
void tryFunc(bool(*func)(int), const int& n);

int main() {
    int n = 9;

    tryFunc(isEven_1, n);
    tryFunc(isEven_2, n);
    tryFunc(isEven_3, n);
    tryFunc(isEven_4, n);
    tryFunc(isEven_5, n);
    tryFunc(isDivisibleBy8_1, n);
    tryFunc(isDivisibleBy8_2, n);
    tryFunc(isDivisibleBy8_3, n);

    return 0;
}

/*
* isEven functions in order of most efficient to less efficient
*/

//0.0036088 s
bool isEven_1(const int& a) {
    return !(a & 1);
}

//0.0036201 s
bool isEven_2(const int& a) {
    return !(a%2);
}

//0.0045625 s
bool isEven_3(const int& a) {
    int n = a / 2;
    return !(n);
}

//0.0096929 s
bool isEven_4(int a) {
    while( a > 1 ){
        a -= 2;
    }

    return !(a);
}

//0.0204047 s
bool isEven_5(const int& a) {
    int p = 0;
    bool even = true;

    while( p < a ){
        p++;
        even = !even;
    }

    return even;
}

/*
* isDivisibleBy8 functions in order of most efficient to less efficient
*/

//0.0037897 s
bool isDivisibleBy8_1(const int& a) {
    return !(a % 8);
}

//0.003863 s
bool isDivisibleBy8_2(const int& a) {
    return (a & 0x07);
}

//0.006036 s
bool isDivisibleBy8_3(int a) {
    while(a > 7)
        a -= 8;
    
    return !(a);
}