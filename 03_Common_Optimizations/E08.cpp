#include "supp.cpp"

void LoopA_1();
void LoopA_2();
void LoopB_1();
void LoopB_2();
void LoopC_1();
void LoopC_2();

const unsigned N = 10000;

int main() {

    tryFunc(LoopA_1);
    tryFunc(LoopA_2);
    tryFunc(LoopB_1);
    tryFunc(LoopB_2);
    tryFunc(LoopC_1);
    tryFunc(LoopC_2);
}

// 14.7001 s
void LoopA_1() {
    int i, j;
    float x[N], y[N];
    for(i = 0; i < N; ++i)
        if(i == 0) 
            x[i] = 0;
        else if(i == N-1)
            x[i] = N-1;
        else
            x[i] = x[i] + y[i];
}

// 11.6081 s
void LoopA_2() {
    int i, j;
    float x[N], y[N];
    x[0] = 0;
    x[N-1] = N-1;
    for(i = 0; i < N; ++i)
        x[i] = x[i] + y[i];
}

// 10.9662 s
void LoopB_1() {
    int i, j;
    float a, x[N], y[N];
    for(i = 0; i < N; ++i)
        if(a == 0.0)
            x[i] = 0;
        else
            y[i] = x[i] * y[i];
}

// 12.0086 s
void LoopB_2() {
    int i, j;
    float a, x[N], y[N];
    if (a == 0.0){
        for(i = 0; i < N; ++i)
            x[i] = 0;
    } else {
        for(i = 0; i < N; ++i)
            y[i] = x[i] * y[i];
    }
}

// 27.3289 s
void LoopC_1() {
    int i, j;
    float x[N], y[N];
    float a;
    a=0.0;
    for(i=0; i<N; ++i)
        a = a + x[i] * y[i];
}

// 27.3107 s
void LoopC_2() {
    int i, j;
    float x[N], y[N];
    float a = 0.0;
    for(i=0; i<N; ++i)
        a += x[i] * y[i];
}