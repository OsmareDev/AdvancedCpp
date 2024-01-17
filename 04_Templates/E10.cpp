#include <iostream>

template<typename T>
unsigned num_param(T val);

template <typename T, typename... Args>
unsigned num_param(T val, Args... args);

int main() {
    std::cout << num_param(1,2,3,4,5,6,7) << '\n';
}

template<typename T>
unsigned num_param(T val){
    return 1;
}

template <typename T, typename... Args>
unsigned num_param(T val, Args... args){
    return 1 + num_param(args...);
}