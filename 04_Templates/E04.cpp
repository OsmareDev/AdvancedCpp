#include <iostream>
#include <vector>

template<typename T>
void showContainer(const T &it_ini, const T &it_end);


int main() {
    std::vector<int> v = {1,2,3,4,4,5,55,5,6};

    showContainer(v.begin(), v.end());
}

template<typename T>
void showContainer(const T &it_ini, const T &it_end) {
    std::cout << "{ ";
    for (T it = it_ini; it != it_end; ++it){
        std::cout << *it << " ";
    }
    std::cout << "}\n";
}