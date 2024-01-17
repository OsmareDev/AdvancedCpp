#include <iostream>

template<typename T, typename N>
struct Pair {
    T first;
    N second;
};

template<typename T1, typename T2>
void print(const Pair<T1, T2> & p) {
    std::cout << p.first << "-" << p.second;
}

int main() {
    Pair<int, int> p = {1,2};
    print(p);
}