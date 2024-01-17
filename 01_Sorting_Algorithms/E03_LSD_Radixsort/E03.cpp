#include <vector>
#include <iostream>
#include <cmath>

const int MAX = 999;

void radixshort(std::vector<int> numbers) {
    std::vector<std::vector<int>> bucket(10);
    for (int i = 0; i <= log10(MAX); i++) {
        for (int j = 0; j <= 9; j++) {
            bucket[j].clear();
        }

        for (int j = 0; j < numbers.size(); j++) {
            int d = (numbers[j] / (int)pow(10, i)) % 10;
            bucket[d].push_back(numbers[j]);
        }
        int pos = 0;

        for (int i = 0; i < bucket.size(); i++) {
            for (int n : bucket[i]) {
                numbers[pos] = n;
                pos++;
            }
            bucket[i].clear();
        }
        std::cout << std::endl;
        std::cout << "iteration: " << i+1 << std::endl;

        for (int n : numbers) {
            std::cout << n << std::endl;
        }
    }
}

int main() {
    std::vector<int> numbers = { 403, 16, 239, 821, 9, 342, 910, 524, 373, 145 };
    radixshort(numbers);
}