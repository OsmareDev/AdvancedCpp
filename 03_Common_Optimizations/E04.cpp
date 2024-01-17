#include <iostream>

class S1 {
    bool a;           // 1 byte    // will occupy 4 since the next element is a float that occupies 4 bytes
    float b;          // 4 bytes
    unsigned short c; // 2 bytes
}; // 12 bytes

struct S2 {
    bool b1; // 1 byte
    char c;  // 1 byte
    bool b2; // 1 byte
}; // 3 byte

int main() {
    S1 v1[10]; // 120 bytes
    S2 v2[10]; // 30 bytes
    
    std::cout << "Elements inside of S1" << std::endl;
    std::cout << sizeof(bool) << std::endl;                          // 1 byte
    std::cout << sizeof(float) << std::endl;                         // 4 bytes
    std::cout << sizeof(unsigned short) << std::endl;                // 2 bytes
    std::cout << "S1 have a size of:" << std::endl;
    std::cout << sizeof(S1) << std::endl;                            // 12 bytes
    std::cout << "A vector of S1 v1[10] will be:" << std::endl;
    std::cout << sizeof(v1) << std::endl << std::endl;               // 120 bytes

    std::cout << "Elements inside of S2" << std::endl;
    std::cout << sizeof(bool) << std::endl;                          // 1 byte
    std::cout << sizeof(char) << std::endl;                          // 1 byte
    std::cout << sizeof(bool) << std::endl;                          // 1 byte
    std::cout << "S2 have a size of:" << std::endl;
    std::cout << sizeof(S2) << std::endl;                            // 3 bytes
    std::cout << "A vector of S2 v2[10] will be:" << std::endl;
    std::cout << sizeof(v2) << std::endl << std::endl;               // 30 bytes
}