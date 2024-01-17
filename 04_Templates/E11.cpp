#include <iostream>

template<typename T>
T suma(T val);

template <typename T, typename... Args>
T suma(T val, Args... args);

int main() {
    std::cout << suma(1,2,3,4,5,6,7) << '\n';
}

template<typename T>
T suma(T val){
    return val;
}

template <typename T, typename... Args>
T suma(T val, Args... args){
    return val + suma(args...);
}