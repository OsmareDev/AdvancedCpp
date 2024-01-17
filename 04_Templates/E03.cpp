#include <vector>
#include <iostream>

template<typename T>
void printVector(std::vector<T> v);

int main() {
    std::vector<int> v1 = {1,2,3,4,4,4,4,4};
    std::vector<float> v2 = {1,2,3,4,4,4,4,4};

    printVector(v1);
    printVector(v2);
}

template<typename T>
void printVector(std::vector<T> v) {
    for (T aux : v)
        std::cout << aux << "\n";
    
    std::cout << "End of vector of: " << typeid(T).name() << "\n";
}