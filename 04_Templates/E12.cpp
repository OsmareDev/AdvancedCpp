#include <iostream>
#include <limits>

int main() {
    std::cout << "El maximo valor de:\n";
    std::cout << "int:" << std::numeric_limits<int>::max() << '\n';
    std::cout << "long:" << std::numeric_limits<long>::max() << '\n';
    std::cout << "long long:" << std::numeric_limits<long long>::max() << '\n';
}