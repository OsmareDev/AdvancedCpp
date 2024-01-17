# English
In this project, I'm transforming a regular class into a template class and working with some template concepts.

1. Test Program

I've written a program (test_tabla.cpp) to test the Tabla class, which implements a hash table with chaining. The steps of the program include:

- Creating a hash table of the appropriate size for storing 20 students and generating these students to insert into the table.
- Searching for a key that exists in the table and another key that does not exist. The program displays the student or a message like "Student does not exist."

2. Conversion to Template Class

I've converted the Tabla class into a template class, enabling users to utilize it with any type of key or value. As the class is now a template, all the code is included in the header file (table_t.h). The class has been tested with the previous program, and a copy has been stored for next project.

3. Collision List

In the current version, a vector is used for the collision list. I've modified the class to allow the selection of the container to be used as a collision list using a template template parameter. The class supports at least a vector and a list. Program comments indicate which operations should be supported by the container. The program has been tested with both types of containers.

4. Hash Function

I've incorporated a templated hash function object from the <functional> library called std::hash, which has specializations for various types. The class has been tested to ensure it works correctly with the types int and string.

Sometimes, an application may require a specific hash function. I've modified the design of the hash table by adding a new template parameter. This parameter allows the modification of the set of hash functions from the main file, enabling the use of different hash functions as needed. This parameter can be considered a policy class. I've also tested these modifications for the types int and string.

# Castellano
En este proyecto, estoy transformando una clase normal en una clase de plantilla y trabajando con algunos conceptos de plantilla.

1. Programa de prueba

Escribí un programa (test_tabla.cpp) para probar la clase Tabla, que implementa una tabla hash con encadenamiento. Los pasos del programa incluyen:

- Crear una tabla hash del tamaño apropiado para almacenar 20 estudiantes y generar estos estudiantes para insertarlos en la tabla.
- Buscando una clave que existe en la tabla y otra clave que no existe. El programa muestra al estudiante o un mensaje como "El estudiante no existe".

2. Conversión a clase de plantilla

Convertí la clase Tabla en una clase de plantilla, lo que permite a los usuarios utilizarla con cualquier tipo de clave o valor. Como la clase ahora es una plantilla, todo el código se incluye en el archivo de encabezado (table_t.h). La clase ha sido probada con el programa anterior y se ha almacenado una copia para el próximo proyecto.

3. Lista de colisiones

En la versión actual, se utiliza un vector para la lista de colisiones. Modifiqué la clase para permitir que la selección del contenedor se use como una lista de colisiones usando un parámetro de plantilla. La clase admite al menos un vector y una lista. Los comentarios del programa indican qué operaciones deben ser compatibles con el contenedor. El programa ha sido probado con ambos tipos de contenedores.

4. Función hash

He incorporado un objeto de función hash con plantilla de la biblioteca <funcional> llamada std::hash, que tiene especializaciones para varios tipos. La clase ha sido probada para garantizar que funciona correctamente con los tipos int y string.

A veces, una aplicación puede requerir una función hash específica. Modifiqué el diseño de la tabla hash agregando un nuevo parámetro de plantilla. Este parámetro permite la modificación del conjunto de funciones hash del archivo principal, permitiendo el uso de diferentes funciones hash según sea necesario. Este parámetro puede considerarse una clase de política. También probé estas modificaciones para los tipos int y string.