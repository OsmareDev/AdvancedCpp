# English
In this project, I'm transforming a regular class into a template class and working with some template concepts learned in theory classes.
1. Test Program

I've written a program (test_tabla.cpp) to test the Tabla class, which implements a hash table with chaining. The steps of the program include:

    Creating a hash table of the appropriate size for storing 20 students and generating these students to insert into the table.
    Searching for a key that exists in the table and another key that does not exist. The program displays the student or a message like "Student does not exist."

2. Conversion to Template Class

I've converted the Tabla class into a template class, enabling users to utilize it with any type of key or value. As the class is now a template, all the code is included in the header file (table_t.h). The class has been tested with the previous program, and a copy has been stored for project 6.
3. Collision List

In the current version, a vector is used for the collision list. I've modified the class to allow the selection of the container to be used as a collision list using a template template parameter. The class supports at least a vector and a list. Program comments indicate which operations should be supported by the container. The program has been tested with both types of containers.
4. Hash Function

I've incorporated a templated hash function object from the <functional> library called std::hash, which has specializations for various types. The class has been tested to ensure it works correctly with the types int and string.

Sometimes, an application may require a specific hash function. I've modified the design of the hash table by adding a new template parameter. This parameter allows the modification of the set of hash functions from the main file, enabling the use of different hash functions as needed. This parameter can be considered a policy class. I've also tested these modifications for the types int and string.

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