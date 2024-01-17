# E01
## English
In C++11 a new class template has been defined, tuple (defined in <tuple>), that allows to define a tuple of data types. Using this class, we defined the function dividir(x,y) that returns in a tuple the quotient and the remainder of the division of x by y.
## Español
En C++11 se ha definido una nueva plantilla de clase, tupla (definida en <tuple>), que permite definir una tupla de tipos de datos. Usando esta clase definimos la función dividir(x,y) que devuelve en una tupla el cociente y el resto de la división de x entre y.

# E03
## English
The code sums the elements of a container of the STL passing as input parameters the begin iterator and end iterator. The elements can be of any summable type (integers, reals, complex numbers, ...). All iterators of the STL have defined an iterator_traits. It is assumed that the result of the addition always fits in the same data type.
## Español
The code adds the elements of an STL container by passing the start iterator and the end iterator as input parameters. The elements can be of any summable type (integers, real, complex,...). All iterators in the STL have defined an iterator_traits. It is assumed that the result of the sum always fits into the same data type.

# E04
## English
Function template for creating a container of random numbers of any integer type. The range of the values is given by the parameters begin and end. The template parameter is the type of the container. Prevented the call to this function with a type different from an integer type by using static asserts.
## Español
Función template para crear un contenedor de números aleatorios de cualquier tipo entero. El rango de valores viene dado por los parámetros inicio y fin. El parámetro de plantilla es el tipo de contenedor. Se evitó la llamada a esta función con un tipo diferente de un tipo entero mediante el uso de afirmaciones estáticas.

# E05
## English
Function template that calculates the mean of the elements of a container. The function will only receive iterators to the container. Write a policy class to allow the calculation of the geometric mean and the harmonic mean with the same function.
## Español
Plantilla de función que calcula la media de los elementos de un contenedor. La función solo recibirá iteradores en el contenedor. Escriba una clase de política que permita el cálculo de la media geométrica y la media armónica con la misma función.

# E06
## English
Class template that converts an integer representing a binary number in its equivalence in base 10 (1101 -> 13). The calculation will be done at compilation time.
## Español
Plantilla de clase que convierte un número entero que representa un número binario en su equivalencia en base 10 (1101 -> 13). El cálculo se realizará en el momento de la compilación.

# E07
## English
Rewrited the previous function using a constexpr function.
## Español
Reescrita la funcion anterior usando constexpr.

# E08
## English
We have a program that executes many times the product of the elements of small vectors. With the idea of optimizing the program, I writed a template that unfolds the product.
## Español
Tenemos un programa que ejecuta muchas veces el producto de los elementos de vectores pequeños. Con la idea de optimizar el programa, escribí una plantilla que desarrolla el producto.

# E09
## English
We have a program that executes many times the initialization of small C-style vectors. With the objective of optimizing the program, we have written a template that unfolds the initialization loop.

## Español
Tenemos un programa que ejecuta la inicialización de pequeños vectores estilo C muchas veces. Para optimizar el programa, hemos escrito una plantilla que realiza el ciclo de inicialización.

# E10
## English
Modification of E04 to allow integer and real types. We have two functions with the same name and I will enable only one of them depending on the type of the container, using enable_if of the library type_traits. The enable_if construction will substitute the return type of the functions.

## Español
Modificación de E04 para permitir tipos enteros y reales. Tenemos dos funciones con el mismo nombre y habilitaré solo una de ellas dependiendo del tipo de contenedor, usando enable_if de la biblioteca type_traits. La construcción enable_if sustituirá el tipo de retorno de las funciones.
