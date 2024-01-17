#include <iostream>
#include <vector>


template<typename T1, typename T2>
std::string format(const T1& container, const T2& func);

struct Point {
    float x,y;
};

int main() {
    std::vector<Point> v(5);

    std::cout << format(v, [](Point value){return "{" + std::to_string(value.x)+","+std::to_string(value.y) + "}";});
}

template<typename T1, typename T2>
std::string format(const T1& container, const T2& func){
    std::string str = "";

    for (auto & item : container)
        str += func(item);

    str += '\n';

    return str;
}