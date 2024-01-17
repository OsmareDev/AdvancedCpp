/**
 * Class to represent students
 */

#include <iostream>
#include <string>
#include <random>
#include <array>

using std::string;

#ifndef _ALUMNO_H_
#define _ALUMNO_H_

class Alumno
{
    string dni;
    string nombre;
    string apellidos;
    unsigned curso;
    unsigned telefono;
    
    static const unsigned NUM_NOMBRE = 15;
    static std::array<string, NUM_NOMBRE> list_nombre;
    static std::array<string, NUM_NOMBRE> list_apellido;
    static std::default_random_engine rnd;


public:
    /**
     * Default constructor.
      * Create an empty student.
     */
    Alumno() {};
    /**
     * Create a student for a specific course, with the rest of the data random.
      * @param curs Student course
     */
    Alumno(unsigned curs);
    /**
     * Returns the DNI to use as a key.
      * @return student ID.
     */
    string getDNI() const 
        {return dni; };
        
    friend std::ostream & operator<<(std::ostream &, const Alumno &);
             
};

#endif
