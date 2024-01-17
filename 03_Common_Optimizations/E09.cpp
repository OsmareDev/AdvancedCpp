#include <vector>
#include "crono.cpp"

const int tam_vec = 200000000;

std::vector<float> addVectors(const std::vector<float>& v1, const std::vector<float>& v2);

int main() {
    

    std::vector<float> v1(tam_vec, 2.f);
    std::vector<float> v2(tam_vec, 3.f);

    addVectors(v1, v2);

}

std::vector<float> addVectors(const std::vector<float>& v1, const std::vector<float>& v2) {
    Cronometro crono;
    std::vector<float> v3(tam_vec, 0.f);

    for (unsigned i = 0; i < tam_vec; ++i) {
        v3[i] = v1[i] + v2[i];
    }

    return v3;
}
