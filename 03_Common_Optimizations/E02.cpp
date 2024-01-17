#include "supp.cpp"

unsigned mult_1(const unsigned& a);
unsigned mult_2(const unsigned& a);
unsigned mult_3(const unsigned& a);

int main() {
    unsigned n = 10;

    tryFunc(mult_1, n);
    tryFunc(mult_2, n);
    tryFunc(mult_3, n);

    return 0;
}

//0.004419 s
unsigned mult_1(const unsigned& a) {
    unsigned b = a * 5;
    return b;
}

// this should be faster but in the test shows the contrary
//0.0051662 s
unsigned mult_2(const unsigned& a) {
    unsigned b = (a << 2) + a;

    return b;
}

//0.0158809 s
unsigned mult_3(const unsigned& a) {
    unsigned b = 0;

    for (int i = 0; i < 5; i++)
        b += a;
    
    return b;
}