#include <vector>
#include <random>

const int TAM = 30;

template <typename T>
T createRandCont(const int& min, const int& max);

int main() {
    std::vector<int> v = createRandCont<std::vector<int>>(0, 10);
}

template <typename T>
T createRandCont(const int& min, const int& max) {
    std::random_device rd;
    std::uniform_int_distribution<int> d(min, max);
	std::mt19937 gen(rd());

    T vec(TAM);

    for (int &i : vec)
        i = d(gen);

    return vec;
}