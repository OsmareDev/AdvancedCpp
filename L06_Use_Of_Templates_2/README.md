# English
In this project, I've learned how to create iterators for custom containers. First, I created iterators for the Lista class, a simple single-linked list. Then, I extended this knowledge to add iterators to the hash table from the previous project (Project 5), making it usable in a manner similar to any STL container.

1. Iterators for a List Class
I created the ListaIterator class in the lista.h file, implementing iterators for the Lista class. This template class derives from std::iterator<std::forward_iterator_tag, T>, where T is the type contained in the container. The class overloads operators such as ==, !=, *(unary), ++ prefix, and ++ postfix. I added two new methods to the Lista class: begin() and end(), which return iterators to the first node and one past the last element (nullptr for a list). Additionally, I defined some type aliases (typedef or using) inside the container to enable generic algorithms for containers to use Lista.

2. Test of the Iterators

To validate the iterators, I implemented the following tests:

- Executed code with a list of integers (l1):
- Created a generic function to display all elements of a container, which takes iterators begin and end as input parameters. Used this function to show the list.
- Copied all elements of the list to a vector using the STL function copy and displayed the vector with the previous function.
- Obtained the minimum element with the STL function min_element.

3. Iterators for the Hash Table

In this section, I created the TablaIterator class to implement iterators for the hash table. This template class has a template parameter representing the type contained in the container (celda struct). I added some methods and functions to the celda struct: operator<< for displaying the celda and operator< for obtaining the minimum value by comparing keys. I overloaded the necessary operators and defined the begin() and end() methods. Appropriate type definitions (iterator and value_type) were included inside the class.

I conducted tests for these iterators following the same steps as in section 2, ensuring that the iterators are of small size for efficiency.

# Castellano
En este proyecto, aprendí a crear iteradores para contenedores personalizados. Primero, creé iteradores para la clase List, una lista simple con un solo enlace. Luego, amplié este conocimiento para agregar iteradores a la tabla hash del proyecto anterior (Proyecto 5), haciéndola utilizable de manera similar a cualquier contenedor STL.

1. Iteradores para una clase de lista
Creé la clase ListaIterator en el archivo Lista.h, implementando iteradores para la clase Lista. Esta clase de plantilla deriva de std::iterator<std::forward_iterator_tag, T>, donde T es el tipo contenido en el contenedor. La clase sobrecarga operadores como ==, !=, *(unario), prefijo ++ y postfijo ++. Agregué dos nuevos métodos a la clase List: comenzar() y finalizar(), que devuelven iteradores al primer nodo y uno más allá del último elemento (nullptr para una lista). Además, definí algunos alias de tipos (typedef o usando) dentro del contenedor para permitir que algoritmos genéricos para que los contenedores usen List.

2. Prueba de los iteradores

Para validar los iteradores, implementé las siguientes pruebas:

- Código ejecutado con una lista de números enteros (l1):
- Creé una función genérica para mostrar todos los elementos de un contenedor, que toma los iteradores de inicio y fin como parámetros de entrada. Usó esta función para mostrar la lista.
- Copié todos los elementos de la lista a un vector usando la función STL copiar y mostré el vector con la función anterior.
- Obtuve el elemento mínimo con la función STL min_element.

3. Iteradores para la tabla hash

En esta sección, creé la clase TablaIterator para implementar iteradores para la tabla hash. Esta clase de plantilla tiene un parámetro de plantilla que representa el tipo contenido en el contenedor (estructura de celda). Agregué algunos métodos y funciones a la estructura de la celda: operador<< para mostrar la celda y operador< para obtener el valor mínimo comparando claves. Sobrecargué los operadores necesarios y definí los métodos comenzar() y finalizar(). Se incluyeron definiciones de tipo apropiadas (iterador y tipo_valor) dentro de la clase.

Realicé pruebas para estos iteradores siguiendo los mismos pasos que en la sección 2, asegurándome de que los iteradores sean de tamaño pequeño para mayor eficiencia.