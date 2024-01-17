#include <math.h>
#include <iostream>

constexpr int B2D(int n, int i = 0) {
    return (n <= 0) ? 0 : ((n%10)<<i) + B2D(n/10, ++i);
}

int main() {
    std::cout << "1101: " << B2D(1101) << '\n';
    std::cout << "1000: " << B2D(1000) << '\n';
    std::cout << "1001: " << B2D(1001) << '\n';
    std::cout << "0001: " << B2D(0001) << '\n';
}