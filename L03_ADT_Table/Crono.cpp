#include <ctime>
#include <iostream>

struct Cronometro {
    timespec start, stop;
    double time;
    
    Cronometro(){
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
    }

    ~Cronometro(){
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop);

        time = (stop.tv_sec - start.tv_sec) + (stop.tv_nsec - start.tv_nsec) * 1e-9;
        std::wcout << time << std::endl;
    }
};