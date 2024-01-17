#include <iostream>

template<typename T>
int sizeof_bits();

int main() {
    std::cout << "Char: Tamanyo en bits: " << sizeof_bits<char>() << std::endl;
    std::cout << "Int: Tamanyo en bits: " << sizeof_bits<int>() << std::endl;
    std::cout << "Float: Tamanyo en bits: " << sizeof_bits<float>() << std::endl;
}

template<typename T>
int sizeof_bits(){
    return sizeof(T)*8;
}