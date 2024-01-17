#include <iostream>
#include <any>
#include <vector>
#include <list>
#include "tabla_t.h"
#include "tabla_t.cpp"
#include "alumno.h"

const unsigned n_alumnos = 20;


class Policy { // nothing
    public:
    static unsigned Hashing(int clave){
        return (clave << 2 * 4 % 7);
    }

    static unsigned Hashing(std::string clave){
        unsigned long h = 5381;
    
        // Only valid for strings
        for(unsigned i = 0; i < clave.size(); i++)
            h = ((h << 5) + h) + clave[i];

        return h;
    }
};


int main() {

    string dni_ejemplo;

    // 1
    // A hash table is created to store 20 students
    
    Tabla<std::string, Alumno, std::list, Policy> clase(n_alumnos);
    Tabla<unsigned, unsigned, std::list> clase2(n_alumnos);

    // 20 students are generated and inserted
    for (unsigned i = 0; i < n_alumnos; ++i){
        Alumno alu(1);
        dni_ejemplo = alu.getDNI();
        clase.insertar(alu.getDNI(), alu);
        clase2.insertar(i, i);
    }

    // 2
    // looking for a student by existing password
    Alumno alu1, alu2;
    unsigned x;
    if (clase.buscar(dni_ejemplo, alu1))
        std::cout << alu1 << '\n';
    else
        std::cout << "Student does not exist" << '\n';

    // looking for a student by password that does not exist
    if(clase.buscar("00000000A", alu2))
        std::cout << alu2 << '\n';
    else
        std::cout << "Student does not exist" << '\n';
    
    if (clase2.buscar(2, x))
        std::cout << x << '\n';
    else
        std::cout << "number does not exist" << '\n';
}