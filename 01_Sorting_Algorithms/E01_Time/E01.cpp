#include <time.h>
#include <iostream>
#define BILLION 1000000000L;

void f(int i) {
    return;
}

int main() {
    timespec start, stop;
    double time;
    clock_gettime(CLOCK_REALTIME, &start);

    for (int i = 1; i <= 1000; ++i)
        f(i);

    clock_gettime(CLOCK_REALTIME, &stop);
    time = (stop.tv_sec - start.tv_sec) + (stop.tv_nsec - start.tv_nsec) / BILLION;
    std::cout << time << std::endl;
}