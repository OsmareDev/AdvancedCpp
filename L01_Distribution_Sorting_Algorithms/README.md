# English
1. Random Vectors Generation

Here we implement a function to generate vectors of the Value struct, where each element contains an integer random key. The function takes parameters such as the vector, the lower and upper limits of the key values, and the state of the Mersenne Twister engine (e.g., mt19937). The vector class from the C++ Standard Template Library (STL) is utilized. The Mersenne Twister engine ensures quality random numbers, and passing its state allows maintaining consistency.

2. CountSort Algorithm

Here, we implement the CountSort algorithm in C++, where the upper bound for key values in the vector is a function parameter. The input vector, of the STL, will be sorted in place using the CountSort algorithm. It is tested with vectors of 20 elements having key values in the ranges [0..255] and [0..65535].

3. RadixSort Algorithm for Vectors

This section involves the implementation of the RadixSort algorithm, specifically in base 10, for vectors. The upper bound for key values is an input parameter. The vector, provided as an STL vector, will be sorted in place using RadixSort. Testing is conducted on vectors of 20 elements with values in the ranges [0..255] and [0..65535].

4. RadixSort Algorithm for Lists

Extending the RadixSort algorithm, this implementation is tailored for sorting dynamic lists. The input parameter is a doubly-linked list from the STL (std::list). The result overwrites the input list. To validate correctness, testing is performed on lists equivalent to vectors tested in the previous step.

# Castellano
1. Generación de vectores aleatorios

Aquí implementamos una función para generar vectores de la estructura Valor, donde cada elemento contiene una clave aleatoria entera. La función toma parámetros como el vector, los límites inferior y superior de los valores clave y el estado del motor Mersenne Twister (por ejemplo, mt19937). Se utiliza la clase vectorial de la biblioteca de plantillas estándar (STL) de C++. El motor Mersenne Twister garantiza números aleatorios de calidad y pasar su estado permite mantener la coherencia.

2. Algoritmo de clasificación de recuento

Aquí, implementamos el algoritmo CountSort en C++, donde el límite superior de los valores clave en el vector es un parámetro de función. El vector de entrada, del STL, se ordenará en su lugar utilizando el algoritmo CountSort. Se prueba con vectores de 20 elementos que tienen valores clave en los rangos [0..255] y [0..65535].

3. Algoritmo RadixSort para vectores

Esta sección involucra la implementación del algoritmo RadixSort, específicamente en base 10, para vectores. El límite superior de los valores clave es un parámetro de entrada. El vector, proporcionado como un vector STL, se ordenará en su lugar mediante RadixSort. Las pruebas se realizan en vectores de 20 elementos con valores en los rangos [0..255] y [0..65535].

4. Algoritmo RadixSort para listas

Esta implementación, que amplía el algoritmo RadixSort, está diseñada para ordenar listas dinámicas. El parámetro de entrada es una lista doblemente enlazada de STL (std::list). El resultado sobrescribe la lista de entrada. Para validar la corrección, las pruebas se realizan en listas equivalentes a los vectores probados en el paso anterior.