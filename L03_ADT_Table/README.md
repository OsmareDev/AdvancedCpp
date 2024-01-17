# English
In this project, we aim to compare different implementations of the Table Abstract Data Type (ADT) in the C++ Standard Template Library (STL), specifically focusing on the map and unordered_map classes. The primary criteria for evaluation include ease of use and the efficiency of each implementation. Our practical application will involve counting the occurrences of words in a given text. Additionally, we will explore mechanisms for implementing internationalization in C++, with a specific emphasis on the locale class.

1. Reading of a Text

Initially, our objective is to read an entire text file and store its contents in memory to ensure that this process does not impact the measurement of execution times. A dedicated function will be created for reading the text file. All words in the text will be stored in a vector of strings, with all letters converted to lowercase for consistent word comparison. Moreover, separators and extraneous characters such as periods, commas, and dashes will be eliminated.

Given that the texts are encoded in UTF-8 and are in Spanish, we will work with wide characters for ease of character manipulation. Utilizing wide versions of strings and streams (wifstream, wcout, wstring, etc.) is essential. It is crucial to set the appropriate locale, and for a Spanish text, we will set the global locale to "es_ES.utf8" using the static method std::locale::global(…). To convert characters to lowercase and remove extraneous characters, the facet ctype is recommended. Note that both cout and wcout should not be used in the same program, and C language locales (defined in <locale.h> or <clocale>) should be avoided.

2. Use of the map Class

We will employ the map class to count the number of repetitions of each word in the texts. The word will serve as the key, and the associated value will represent the number of times the word occurs. A dedicated function will implement the counting process, taking the vector of words as input and providing the map with the repetition counts as output. This function will be tested using the file "texto1.txt," and the resulting map will be displayed. The cost of this function will be calculated in seconds using clock_gettime() (or the chrono library), using "texto2.txt" for testing. Sufficient repetitions will be performed to accurately measure the execution time, with total execution times expected in the order of seconds when compiling with the option –O2.

3. Use of the unordered_map Class

Similar to the previous section, we will implement a function using the unordered_map class of the STL. Execution times will be obtained using the same number of repetitions for comparison.

4. Calculation of the Most Used Words

To enhance the program's functionality, a function will be added to display the 30 most frequently used words, ordered from the most used to the least used. An efficient algorithm will be employed for this task.

# Castellano
En este proyecto, nuestro objetivo es comparar diferentes implementaciones del tipo de datos abstractos de tabla (ADT) en la biblioteca de plantillas estándar (STL) de C++, centrándonos específicamente en las clases map y unordered_map. Los criterios principales para la evaluación incluyen la facilidad de uso y la eficiencia de cada implementación. Nuestra aplicación práctica implicará contar las apariciones de palabras en un texto determinado. Además, exploraremos mecanismos para implementar la internacionalización en C++, con un énfasis específico en la clase local.

1. Leer un texto

Inicialmente, nuestro objetivo es leer un archivo de texto completo y almacenar su contenido en la memoria para asegurar que este proceso no afecte la medición de los tiempos de ejecución. Se creará una función dedicada para leer el archivo de texto. Todas las palabras del texto se almacenarán en un vector de cadenas, y todas las letras se convertirán a minúsculas para una comparación coherente de las palabras. Además, se eliminarán los separadores y caracteres superfluos como puntos, comas y guiones.

Dado que los textos están codificados en UTF-8 y están en español, trabajaremos con caracteres anchos para facilitar la manipulación de caracteres. Es esencial utilizar versiones amplias de cadenas y transmisiones (wifstream, wcout, wstring, etc.). Es crucial configurar la configuración regional adecuada y, para un texto en español, configuraremos la configuración regional global en "es_ES.utf8" usando el método estático std::locale::global(…). Para convertir caracteres a minúsculas y eliminar caracteres superfluos, se recomienda la faceta ctype. Tenga en cuenta que cout y wcout no deben usarse en el mismo programa y que se deben evitar las configuraciones regionales del lenguaje C (definidas en <locale.h> o <clocale>).

2. Uso del mapa Clase

Emplearemos la clase de mapa para contar el número de repeticiones de cada palabra en los textos. La palabra servirá como clave y el valor asociado representará la cantidad de veces que aparece la palabra. Una función dedicada implementará el proceso de conteo, tomando el vector de palabras como entrada y proporcionando al mapa los conteos de repetición como salida. Esta función se probará utilizando el archivo "texto1.txt" y se mostrará el mapa resultante. El costo de esta función se calculará en segundos usando clock_gettime() (o la biblioteca crono), usando "texto2.txt" para realizar pruebas. Se realizarán suficientes repeticiones para medir con precisión el tiempo de ejecución, y se esperan tiempos de ejecución totales del orden de segundos al compilar con la opción –O2.

3. Uso de la clase unordered_map

De manera similar a la sección anterior, implementaremos una función usando la clase unordered_map de STL. Los tiempos de ejecución se obtendrán utilizando el mismo número de repeticiones para comparar.

4. Cálculo de las palabras más utilizadas

Para mejorar la funcionalidad del programa, se agregará una función para mostrar las 30 palabras más utilizadas, ordenadas desde las más utilizadas hasta las menos utilizadas. Para esta tarea se empleará un algoritmo eficiente.