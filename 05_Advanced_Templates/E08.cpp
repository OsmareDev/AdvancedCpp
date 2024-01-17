#include <vector>
#include <iostream>

template<unsigned N>
struct multiplication {
    template <typename T>
    static int const res(T v) { return multiplication<N-1>::res(v) * v[N-1]; };
};

template<>
struct multiplication<0> {
    template <typename T>
    static int const res(T v) { return 1; };
};

int main() {
    std::vector<int> v = {10, 4, 7};
    std::cout << multiplication<3>::res(v) << '\n';
}