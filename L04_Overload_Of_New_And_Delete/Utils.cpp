#include <ctime>
#include <vector>
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

/*
* Functions to test in loops
*/
const int N_LOOPS = 10000;

/**********************************************************************/ /**
*
*  Function that accepts a call from a function whose efficiency we are going to test
* measuring in a loop a limited number of times its use
*
* @param [in] func Lambda of the function to be tested in the loop
*
*/
/**********************************************************************/
void tryFunc(void(*func)()) {
    Cronometro c;

    for (int i = 0; i < N_LOOPS; i++) {
        func();
    }
}

/**********************************************************************/ /**
*
*  Function that accepts a call from a function whose efficiency we are going to test
* measuring in a loop a limited number of times its use
*
* @param [in] func Lambda of the function to be tested in the loop
* @param [in] vec vector with the deletion indices that are passed to the function
*
*/
/**********************************************************************/
void tryFunc(void(*func)(const std::vector<int>& v), std::vector<int> vec) {
    Cronometro c;

    for (int i = 0; i < N_LOOPS; i++) {
        func(vec);
    }
}