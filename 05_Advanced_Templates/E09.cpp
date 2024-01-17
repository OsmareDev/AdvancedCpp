#include <iostream>

template<unsigned N>
struct inicializa {
    template <typename T>
    static inline void constexpr ini(T* v, T x) { v[N] = x; inicializa<N-1>::ini(v, x); };
};

template<>
struct inicializa<0> {
    template <typename T>
    static inline void const ini(T* v, T x) { v[0] = x; };
};

int main() {
    int i[5];
    inicializa<4>::ini(i, 5);

    for (int x : i) {
        std::cout << x << '\n';
    }
}