#include <iostream>

unsigned bitcount(unsigned a);

int main() {
    unsigned n = 10; 
    std::cout << "En " << n << " hay " << bitcount(n) << " bits a 1." << std::endl;
}

unsigned bitcount(unsigned a) {
    unsigned b = 0;

    while(a){
        b += (a & 1);
        a >>= 1;
    }

    return b;
}