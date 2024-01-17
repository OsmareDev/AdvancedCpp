# English

In this project, I created an implementation of the Floyd algorithm, which calculates the shortest paths between all nodes in a graph using dynamic programming. I began by implementing a versatile Graph class template with parameters for the type of edge weight and the number of nodes in the graph. The graph was represented by an adjacency matrix implemented as a C-style matrix. I included range checking using assertions to ensure robustness.

1. Implementation of the Graph class

The Graph class template was designed to be fixed in size once declared, and it was validated to ensure correct functionality.

2. Floyd algorithm

I implemented the basic Floyd algorithm as an independent function in floyd.cpp. The function took a Graph object as an input parameter and produced a matrix representing the minimum distances between all nodes. Additionally, I created a function for generating an undirected random graph with numerical weights, utilizing the STL library's random. The enable_if template was employed to make the method compatible with both integer and real numbers. I tested the algorithm on a randomly generated graph of size 6, validating its correctness.

3. Calculation of the shortest path

Expanding on the basic Floyd algorithm, I modified it in floyd2.cpp to also calculate and output the shortest paths, providing the sequence of nodes to be visited.

To demonstrate the enhanced functionality, I showcased the shortest paths from nodes 0 and 1 to all other nodes in a graph of size 8, following the same characteristics as the previous example. The program was tested to ensure its accuracy.

This project served as a valuable exercise in implementing a fundamental graph algorithm and enhancing its capabilities for practical use.

# Castellano

En este proyecto, creé una implementación del algoritmo Floyd, que calcula los caminos más cortos entre todos los nodos en un gráfico mediante programación dinámica. Comencé implementando una plantilla de clase Graph versátil con parámetros para el tipo de peso de borde y la cantidad de nodos en el gráfico. El gráfico fue representado por una matriz de adyacencia implementada como una matriz estilo C. Incluí verificación de rango mediante afirmaciones para garantizar la solidez.

1. Implementación de la clase Graph.

La plantilla de clase Graph se diseñó para tener un tamaño fijo una vez declarada y se validó para garantizar una funcionalidad correcta.

2. Algoritmo de Floyd

Implementé el algoritmo básico de Floyd como una función independiente en floyd.cpp. La función tomó un objeto Graph como parámetro de entrada y produjo una matriz que representa las distancias mínimas entre todos los nodos. Además, creé una función para generar un gráfico aleatorio no dirigido con pesos numéricos, utilizando el método aleatorio de la biblioteca STL. Se empleó la plantilla enable_if para que el método fuera compatible tanto con números enteros como reales. Probé el algoritmo en un gráfico de tamaño 6 generado aleatoriamente, validando su exactitud.

3. Cálculo del camino más corto.

Ampliando el algoritmo básico de Floyd, lo modifiqué en floyd2.cpp para calcular y generar también las rutas más cortas, proporcionando la secuencia de nodos que se visitarán.

Para demostrar la funcionalidad mejorada, mostré las rutas más cortas desde los nodos 0 y 1 a todos los demás nodos en un gráfico de tamaño 8, siguiendo las mismas características que en el ejemplo anterior. El programa fue probado para garantizar su precisión.

Este proyecto sirvió como un valioso ejercicio para implementar un algoritmo gráfico fundamental y mejorar sus capacidades para uso práctico.