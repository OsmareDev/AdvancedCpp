# E01
## English
Several versions for checking if a number is even. Sorted from less efficient to more efficient. Same for checking if a number is divisible by 8.
## Español
Varias versiones para comprobar si un número es par. Ordenados de menos eficiente a más eficiente. Lo mismo para comprobar si un número es divisible por 8.

# E02
## English
In many processors, the cost of integer multiplication is greater than other basic operations with integers. Code for calculating x*5 faster than the standard multiplication, being x an unsigned integer.
## Español
En muchos procesadores, el coste de la multiplicación de números enteros es mayor que el de otras operaciones básicas con números enteros. Código para calcular x*5 más rápido que la multiplicación estándar, siendo x un entero sin signo.

# E03
## English
Code for counting the number of bits set to 1 in an unsigned integer. Improved the efficiency of the function taking into account that it will be used for counting the number of bits set in a very long sequence (for example 109 bits).
## Español
Código para contar el número de bits establecidos en 1 en un entero sin signo. Se mejoró la eficiencia de la función teniendo en cuenta que se utilizará para contar el número de bits establecidos en una secuencia muy larga (por ejemplo, 109 bits).

# E04
## English
How many bytes do they occupy? Some tests
## Español
¿Cuantos bytes ocupan? Algunas pruebas

# E05
## English
The following code implements a sequential search in a vector. The optimizations consist in improvements of the algorithm or in adjustments of the code. For each optimization we will check the execution time using the Linux command time. For this purpose, the program should contain an outer loop in order to repeat the function as many times as necessary.
## Español
El siguiente código implementa una búsqueda secuencial en un vector. Las optimizaciones consisten en mejoras del algoritmo o en ajustes del código. Para cada optimización comprobaremos el tiempo de ejecución utilizando el tiempo de comando de Linux. Para ello, el programa debe contener un bucle externo para poder repetir la función tantas veces como sea necesario.

# E06
## English
The following code evaluates a polynomial of grade n in the point x. The optimizations consist in improvements of the algorithm or in adjustments of the code. For each optimization we will check the execution time using the Linux command time. For this purpose, the program should contain an outer loop in order to repeat the function as many times as necessary.
## Español
El siguiente código evalúa un polinomio de grado n en el punto x. Las optimizaciones consisten en mejoras del algoritmo o en ajustes del código. Para cada optimización comprobaremos el tiempo de ejecución utilizando el tiempo de comando de Linux. Para ello, el programa debe contener un bucle externo para poder repetir la función tantas veces como sea necesario.

# E07
## English
array of structures (AOS) vs structure of arrays (SOA).
## Español
matriz de estructuras (AOS) vs estructura de matrices (SOA).

# E08
## English
Loop optimization
## Español
Optimizacion de bucles

# E09
## English
Program in C++ for adding 2 vectors of float numbers. Compiled the program with the appropriate options so the loop is vectorized. Obtained execution times before and after vectorizing to check that the final version is correctly vectorized.
// without vectorization
// g++ -Wall ./ej9.cpp -o ./ej9
// time: 3.03842 s

// with vectorization
// g++ -Wall ./ej9.cpp -o ./ej9 -mavx -O2 -ffast-math -ftree-vectorize
// time: 0.355744 s

## Español
Programa en C++ para sumar 2 vectores de números flotantes. Compilé el programa con las opciones adecuadas para que el bucle quede vectorizado. Se obtuvieron los tiempos de ejecución antes y después de la vectorización para comprobar que la versión final está correctamente vectorizada.
// sin vectorización
// g++ -Wall ./ej9.cpp -o ./ej9
// tiempo: 3,03842 s

// con vectorización
// g++ -Wall ./ej9.cpp -o ./ej9 -mavx -O2 -ffast-math -ftree-vectorize
// tiempo: 0,355744 s