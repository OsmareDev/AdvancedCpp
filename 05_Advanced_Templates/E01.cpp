#include <tuple>
#include <iostream>

std::tuple<int, int> division(int x, int y);

int main() {
    std::tuple<int,int> t;
    int x = 7, y = 3;
    t = division(x, y);

    std::cout << "Resultado: " << std::get<0>(t) << '\n';
    std::cout << "Resto: " << std::get<1>(t) << '\n';
}

std::tuple<int, int> division(int x, int y) {
    std::tuple<int, int> t;
    std::get<0>(t) = x / y;
    std::get<1>(t) = x % y;
    return t;
}