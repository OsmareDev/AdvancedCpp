#include <iostream>
#include <memory>
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock
#include <algorithm>    // std::shuffle
#include "Utils.cpp"

constexpr int N = 10000;

void memcost1();
void memcost2(const std::vector<int> &vectorIndex);
void memcost3();
void memcost4();

struct Prueba {
    float f1, f2;
    int i1, i2, i3;

    static unsigned char pool[];
    static bool alloc_map[];
    static unsigned cabeza;

    void* operator new(size_t sz)
    {
        for(int i = cabeza; i < N; i++)
            if(!alloc_map[i]) {
                // std::cout << "using block " << i << " ... ";
                alloc_map[i] = true;
                cabeza++;
                return pool + (i * sizeof(Prueba));
            }
            else {
                cabeza++;
            }
        // std::cout << "out of memory" << std::endl;
        throw std::bad_alloc();
    }

    void operator delete(void* m)
    {
        if(!m) return; // Check for null pointer
        // Assume it was created in the pool
        // Calculate which block number it is:
        unsigned long block = (unsigned long)m - (unsigned long)pool;
        block /= sizeof(Prueba);
        if (block < cabeza)
            cabeza = block;
        // std::cout << "freeing block " << block << std::endl; // Mark it free:
        alloc_map[block] = false;
    }
};

unsigned char Prueba::pool[N * sizeof(Prueba)];
bool Prueba::alloc_map[N] = {false};
unsigned Prueba::cabeza = 0;


int main() {
    std::vector<int> vectorIndex(N);

    for (int i = 0; i < N; i++) {
        vectorIndex[i] = i;
    }

    // std::suffle
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(vectorIndex.begin(), vectorIndex.end(), std::default_random_engine(seed));


    std::cout << "Static memory: ";
    tryFunc(memcost1);
    std::cout << "Dynamic memory with random erase: ";
    tryFunc(memcost2, vectorIndex);
    std::cout << "Unique Ptr: ";
    tryFunc(memcost3);
    std::cout << "Shared Ptr: ";
    tryFunc(memcost4);
}

/**********************************************************************/ /**
*
*  Function that tests the efficiency of static memory
*
*/
/**********************************************************************/
void memcost1() {
    Prueba p[N];
    
    for (int i = 0; i < N; ++i){
        p[i].i1 = i;
    }

    volatile int suma = 0;
    for (int i = 0; i < N; ++i) {
        suma += p[i].i1;
    }
}

/**********************************************************************/ /**
*
*  Function that checks the efficiency of dynamic memory with the functions of
* overloading new and delete and doing random deletion of pointers
*
* @param [in] vectorIndex Vector of indices with the order in which the indices will be deleted
*
*/
/**********************************************************************/
void memcost2(const std::vector<int>& vectorIndex) {
    Prueba *p[N];

    for (int i = 0; i < N; ++i){
        p[i] = new Prueba;
        p[i]->i1 = i;
    }

    volatile int suma = 0;
    for (int i = 0; i < N; ++i) {
        suma += p[vectorIndex[i]]->i1;
        delete p[vectorIndex[i]];
    }
}

/**********************************************************************/ /**
*
*  Function that tests the efficiency of using unique pointers
*
*/
/**********************************************************************/
void memcost3() {
    std::unique_ptr<Prueba> p[N];

    for (int i = 0; i < N; ++i){
        p[i].reset(new Prueba);
        p[i]->i1 = i;
    }

    volatile int suma = 0;
    for (int i = 0; i < N; ++i) {
        suma += p[i]->i1;
    }
}

/**********************************************************************/ /**
*
*  Function that tests the efficiency of using shared pointers
*
*/
/**********************************************************************/
void memcost4() {
    // the same as memcost3 but with shared_ptr
    std::shared_ptr<Prueba> p[N];

    for (int i = 0; i < N; ++i){
        p[i].reset(new Prueba);
        p[i]->i1 = i;
    }

    volatile int suma = 0;
    for (int i = 0; i < N; ++i) {
        suma += p[i]->i1;
    }
}