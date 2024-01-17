# English
In this project, I explored expression templates and their usage. I began by examining the provided code in Aula Virtual, which demonstrated expression templates, and compiled it to ensure its correctness. However, the code lacked certain operator versions, so I added array-array, scalar-array, and array-scalar versions for each operator. Additionally, I implemented the power operation, which only required an array-scalar version.

For a comprehensive test, I verified the correctness of these operators by evaluating the expression: x = ((1.2 + x) * y + (2.0 * y).pow(2.0) ) * x.

1. Class SArray2

In this section, I implemented the Sarray2 class based on Sarray. Unlike Sarray, I added classical implementations of the +, *, and pow operators. This allowed for a direct comparison between expression templates and the traditional approach to implementing mathematical operators. To validate the Sarray2 class, I solved the same expression from section 1.

2. Compare Execution Times

I measured the execution time (compiled with the -O2 option) for solving the expression with vectors of 1,000,000 elements using both Array and Sarray2. The calculations were repeated multiple times to obtain accurate execution times. I used the Linux time command and recorded three different time metrics for each program.

3. Eigen Library

I utilized the Eigen library, known for its efficient matrix and vector operations using expression templates. Specifically, I employed the Array class for coefficient-wise operations. The program was compiled with the -I /usr/include/eigen3 option to specify the location of Eigen's header files. I solved the same expression from section 1 using Eigen and compared the execution times with the results from section 2.

4. Show the Expression Type

Considering the need to display the type of an expression in a clear way for debugging purposes, I explored options. While the typeid function from the <typeinfo> library is available, its results with templates may not be clear. Thus, I implemented a method within the Array class to show the type of an expression template in a more interpretable manner. This method can be valuable for debugging the array class.

# Castellano
En este proyecto, exploré las plantillas de expresión y su uso. Comencé examinando el código proporcionado en Aula Virtual, que demostraba plantillas de expresión, y lo compilé para garantizar que fuera correcto. Sin embargo, el código carecía de ciertas versiones de operador, por lo que agregué versiones de matriz-matriz, matriz escalar y matriz-escalar para cada operador. Además, implementé la operación de energía, que solo requería una versión escalar de matriz.

Para una prueba exhaustiva, verifiqué la exactitud de estos operadores evaluando la expresión: x = ((1.2 + x) * y + (2.0 * y).pow(2.0) ) * x.

1. Clase SArray2

En esta sección, implementé la clase Sarray2 basada en Sarray. A diferencia de Sarray, agregué implementaciones clásicas de los operadores +, * y pow. Esto permitió una comparación directa entre las plantillas de expresión y el enfoque tradicional para implementar operadores matemáticos. Para validar la clase Sarray2, resolví la misma expresión de la sección 1.

2. Comparar tiempos de ejecución

Medí el tiempo de ejecución (compilado con la opción -O2) para resolver la expresión con vectores de 1.000.000 de elementos usando Array y Sarray2. Los cálculos se repitieron varias veces para obtener tiempos de ejecución precisos. Utilicé el comando de tiempo de Linux y registré tres métricas de tiempo diferentes para cada programa.

3. Biblioteca propia

Utilicé la biblioteca Eigen, conocida por sus eficientes operaciones matriciales y vectoriales utilizando plantillas de expresión. Específicamente, empleé la clase Array para operaciones con coeficientes. El programa fue compilado con la opción -I /usr/include/eigen3 para especificar la ubicación de los archivos de encabezado de Eigen. Resolví la misma expresión de la sección 1 usando Eigen y comparé los tiempos de ejecución con los resultados de la sección 2.

4. Mostrar el tipo de expresión

Teniendo en cuenta la necesidad de mostrar el tipo de expresión de forma clara para fines de depuración, exploré opciones. Si bien la función typeid de la biblioteca <typeinfo> está disponible, es posible que sus resultados con las plantillas no sean claros. Por lo tanto, implementé un método dentro de la clase Array para mostrar el tipo de plantilla de expresión de una manera más interpretable. Este método puede resultar valioso para depurar la clase de matriz.