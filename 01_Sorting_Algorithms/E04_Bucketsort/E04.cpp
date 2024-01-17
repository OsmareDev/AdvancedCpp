#include <vector>
#include <iostream>
#include <cmath>

void insertionShort(std::vector<float>& vec) {
    for (int i = 1; i < vec.size(); i++)
    {
        int j = i;
        while (j > 0 && vec[j] < vec[j - 1])
        {
            float temp = vec[j];
            vec[j] = vec[j - 1];
            vec[j - 1] = temp;
            j--;
        }
    }
}

void bucketShort(std::vector<float>& numbers) {
    std::vector<std::vector<float>> buckets(2000);
    for (int i = 0; i < numbers.size(); i++) {
        int b = floor(numbers.size() * ((numbers[i]+1000) / 1000));
        //int b = floor(numbers[i] / 100) + 10;
        buckets[b].push_back(numbers[i]);
    }

    for (int i = 0; i < 2000; i++) {
        insertionShort(buckets[i]);
    }
    int pos = 0;

    for (int i = 0; i < buckets.size(); i++) {
        for (float n : buckets[i]) {
            numbers[pos] = n;
            pos++;
        }
        buckets[i].clear();
    }
}

int main() {
    std::vector<float> numbers = { -444.1, 246.3, 2.4, -773.6 };
    bucketShort(numbers);

    for (float f : numbers) {
        std::cout << f << std::endl;
    }
}