# English
In this project, we aim to assess the costs associated with dynamic memory allocation as opposed to static memory (using the program stack). Additionally, we will explore potential improvements by overloading the new and delete operators.

1. Comparison of Memory Costs

For a fair comparison, we will create two functions, costeMem1 and costeMem2, each allocating 10,000 objects of class Prueba.

- Function costeMem1
This function allocates objects in static memory (program stack) and performs operations on them. The attribute i1 of each object is assigned the value of its position in the array, and the addition of these values is calculated in a loop. The result is returned as the function output.

- Function costeMem2
This function allocates objects in dynamic memory, using an array of 10,000 pointers to Prueba. Similar to costeMem1, it performs operations on these objects, but in the first loop, it also dynamically allocates the 10,000 objects using the new operator, and in the second loop, it frees all the objects.

Both functions will be executed multiple times to measure execution times accurately, using clock_gettime() or the chrono library.

2. Use of unique_ptr and shared_ptr
Function costeMem3 (unique_ptr)

A third function based on costeMem2, but replacing all pointers with unique_ptr. The goal is to evaluate the use of unique_ptr for memory management.
Function costeMem4 (shared_ptr)

A fourth function based on costeMem2, but replacing all pointers with shared_ptr. This aims to assess the use of shared_ptr.

Comparison of execution times will be performed for the four functions in two scenarios: compiling without optimization and compiling with the option -O2.

3. Overload of new and delete for class Prueba

In this section, we will overload the new and delete operators specifically for the class Prueba. Multiple methods, including a vector of bits or a free-list, will be explored to enhance memory management efficiency. The program from Section 1 will be repeated, and the results will be compared.

4. Changing the Order of Deletion

The order of deletion in costeMem2 will be altered by creating a vector of indexes in the main function and passing it as a parameter to costeMem2. This vector will be utilized for deleting objects in a random order, and the creation of the vector will involve the use of std::shuffle.

A document with a table summarizing all execution times and the derived conclusions will be presented at the end of the project. The programs will be compiled with the -O2 option for optimization.

# Castellano

En este proyecto, nuestro objetivo es evaluar los costos asociados con la asignación de memoria dinámica en comparación con la memoria estática (usando la pila de programas). Además, exploraremos posibles mejoras sobrecargando los operadores nuevos y eliminados.

1. Comparación de los costos de la memoria

Para una comparación justa, crearemos dos funciones, costoMem1 y costoMem2, cada una de las cuales asignará 10,000 objetos de la clase Prueba.

- Función costeMem1
Esta función asigna objetos en la memoria estática (pila de programas) y realiza operaciones sobre ellos. Al atributo i1 de cada objeto se le asigna el valor de su posición en la matriz, y la suma de estos valores se calcula en un bucle. El resultado se devuelve como salida de la función.

- Función costeMem2
Esta función asigna objetos en la memoria dinámica, utilizando una matriz de 10.000 punteros para realizar pruebas. Similar a costoMem1, realiza operaciones en estos objetos, pero en el primer ciclo, también asigna dinámicamente los 10,000 objetos usando el nuevo operador, y en el segundo ciclo, libera todos los objetos.

Ambas funciones se ejecutarán varias veces para medir los tiempos de ejecución con precisión, utilizando clock_gettime() o la biblioteca crono.

2. Uso de Unique_ptr y Shared_ptr
Función costMem3 (unique_ptr)

Una tercera función basada en costoMem2, pero reemplazando todos los punteros con Unique_ptr. El objetivo es evaluar el uso de Unique_ptr para la gestión de memoria.
Función costMem4 (shared_ptr)

Una cuarta función basada en costoMem2, pero reemplazando todos los punteros conshared_ptr. Esto tiene como objetivo evaluar el uso deshared_ptr.

Se realizará una comparación de los tiempos de ejecución para las cuatro funciones en dos escenarios: compilar sin optimización y compilar con la opción -O2.

3. Sobrecarga de pruebas nuevas y eliminadas para clases.

En esta sección, sobrecargaremos los operadores nuevos y de eliminación específicamente para la clase Prueba. Se explorarán múltiples métodos, incluido un vector de bits o una lista libre, para mejorar la eficiencia de la gestión de la memoria. Se repetirá el programa de la Sección 1 y se compararán los resultados.

4. Cambiar el orden de eliminación

El orden de eliminación en costoMem2 se modificará creando un vector de índices en la función principal y pasándolo como parámetro a costoMem2. Este vector se utilizará para eliminar objetos en orden aleatorio, y la creación del vector implicará el uso de std::shuffle.

Al final del proyecto se presentará un documento con una tabla que resume todos los tiempos de ejecución y las conclusiones derivadas. Los programas se compilarán con la opción -O2 para su optimización.