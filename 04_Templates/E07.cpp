#include <vector>
#include <random>

const int TAM = 30;

template <typename T>
std::vector<T> createRandVec(const T& min, const T& max);

int main() {
    std::vector<int> v = createRandVec(0, 10);
    //std::vector<float> v = createRandVec(0.f, 10.f); ERROR
}

template <typename T>
std::vector<T> createRandVec(const T& min, const T& max) {
    static_assert(std::is_integral<T>::value, "no es un entero");

    std::random_device rd;
    std::uniform_int_distribution<T> d(min, max);
	std::mt19937 gen(rd());

    std::vector<T> vec(TAM);
    for (T&i : vec)
        i = d(gen);

    return vec;
}