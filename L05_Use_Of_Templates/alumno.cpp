/**
 * Implementation of the Student class
 */

#include "alumno.h"
#include <iostream>
#include <string>

using std::string;
using std::endl;

// Example names
std::array<string, Alumno::NUM_NOMBRE> Alumno::list_nombre = {
"Javier",
"Jorge",
"Angel",
"Raul",
"José",
"Iñigo",
"Jose Antonio",
"Julio",
"Beatriz",
"Ismael",
"Oliver",
"Carlos",
"Alberto",
"Francisco Manuel",
"Lluís Carles"  };

// Example surnames
std::array<string, Alumno::NUM_NOMBRE> Alumno::list_apellido = {
        "Albaladejo" ,
    "Albiach" ,
    "Aldana" ,
    "Alonso" ,
    "Anda" ,
    "Andres" ,
    "Angel" ,
    "Aranda" ,
    "Bernal" ,
    "Bonell" ,
    "Calderon" ,
    "Chakkour" ,
    "Contreras" ,
    "Correa" ,
    "Dacasa" };

std::default_random_engine Alumno::rnd;

/**
 * Student Builder.
  * Generates a student with random data except the course, which is passed as a parameter.
  * @param curs student course
 */
Alumno::Alumno(unsigned curs): curso(curs)
{
    std::uniform_int_distribution<unsigned> dni_dist(1, 99'999'999);
    std::uniform_int_distribution<char> letter_dist('A', 'Z');
    std::uniform_int_distribution<unsigned> name_dist(0, NUM_NOMBRE-1);
    std::uniform_int_distribution<unsigned> tlf_dist(600'000'000, 699'999'999);

    unsigned num = dni_dist(rnd);
    dni = std::to_string(num);
    dni.push_back( letter_dist(rnd) );
    
    nombre = list_nombre.at( name_dist(rnd) );
    apellidos = list_apellido.at( name_dist(rnd) );
    telefono = tlf_dist(rnd);
}

/**
 * Write the student to an output stream
  * @param out Output stream
  * @param alu student to write
 */
std::ostream & operator<<(std::ostream & out, const Alumno & alu)
{
    const string tab = "    ";
    out << "==================================" << endl;
    out << tab << "DNI: " << alu.dni << endl;
    out << tab << "Nombre: " << alu.nombre << tab << alu.apellidos << endl;;
    out << tab << "Curso: " << alu.curso;
    out << tab << "Teléfono: " << alu.telefono << endl;
    out << "==================================" << endl;
    return out;
}
