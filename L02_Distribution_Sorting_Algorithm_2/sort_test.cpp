/**********************************************************/ /**
 *
 * @file sort_test.cpp
 *
 * Review of some sorting algorithms without comparisons.
 *
 * @date 02-10-2022
 */ /**************************************************************************/

#include <iostream>
#include <random>

#include "CountSort.h"
#include "RadixSort.h"
#include "Value.h"
#include "Crono.cpp"
#include <functional>

/**
 * Maximum of the key of the elements to be sorted, range [0, KEY_MAX]
 */
constexpr unsigned int KEY_MAX1 = 255;
constexpr unsigned int KEY_MIN1 = 0;

constexpr unsigned int KEY_MAX2 = 65535;
constexpr unsigned int KEY_MIN2 = 0;
/**
 * Maximum size of the vector of numbers to sort
 */
constexpr unsigned int SIZE_V = 10000;

/*
 * Prototypes of the functions used,
  * implemented after main()
 */
template <typename T>
void generateRandom(T &vec, std::mt19937& gen, const int KEY_MIN, const int KEY_MAX);
template <typename T>
void ejecutarFuncion(std::function<void(T&, const unsigned int&)> lambda, const unsigned &size, const unsigned &range);

/*
 * Main
 */
int main() {

	std::cout << "\n\n######## sort_test.cpp ########" << std::endl;

	std::cout << "### CountSort : range [0..255] : tam 1000 ###" << std::endl;
	ejecutarFuncion<std::vector<Value>>(countSort, 1000, 255);

	std::cout << "### CountSort : range [0..65535] : tam 1000 ###" << std::endl;
	ejecutarFuncion<std::vector<Value>>(&countSort, 1000, 65535);

	std::cout << "### CountSort : range [0..255] : tam 10000 ###" << std::endl;
	ejecutarFuncion<std::vector<Value>>(&countSort, 10000, 255);

	std::cout << "### CountSort : range [0..65535] : tam 10000 ###" << std::endl;
	ejecutarFuncion<std::vector<Value>>(&countSort, 10000, 65535);

	std::cout << "### CountSort : range [0..255] : tam 100000 ###" << std::endl;
	ejecutarFuncion<std::vector<Value>>(&countSort, 100000, 255);

	std::cout << "### CountSort : range [0..65535] : tam 100000 ###" << std::endl;
	ejecutarFuncion<std::vector<Value>>(&countSort, 100000, 65535);

	// -----------------------

	std::cout << "### LSDRadixSort Vector : range [0..255] : tam 1000 ###" << std::endl;
	ejecutarFuncion<std::vector<Value>>(LSDRadixSortHexV, 1000, 255);

	std::cout << "### LSDRadixSort Vector : range [0..65535] : tam 1000 ###" << std::endl;
	ejecutarFuncion<std::vector<Value>>(LSDRadixSortHexV, 1000, 65535);

	std::cout << "### LSDRadixSort Vector : range [0..255] : tam 10000 ###" << std::endl;
	ejecutarFuncion<std::vector<Value>>(LSDRadixSortHexV, 10000, 255);

	std::cout << "### LSDRadixSort Vector : range [0..65535] : tam 10000 ###" << std::endl;
	ejecutarFuncion<std::vector<Value>>(LSDRadixSortHexV, 10000, 65535);

	std::cout << "### LSDRadixSort Vector : range [0..255] : tam 100000 ###" << std::endl;
	ejecutarFuncion<std::vector<Value>>(LSDRadixSortHexV, 100000, 255);

	std::cout << "### LSDRadixSort Vector : range [0..65535] : tam 100000 ###" << std::endl;
	ejecutarFuncion<std::vector<Value>>(LSDRadixSortHexV, 100000, 65535);

	// ------------------------

	std::cout << "### LSDRadixSort List : range [0..255] : tam 1000 ###" << std::endl;
	ejecutarFuncion<std::list<Value>>(LSDRadixSortHexL, 1000, 255);

	std::cout << "### LSDRadixSort List : range [0..65535] : tam 1000 ###" << std::endl;
	ejecutarFuncion<std::list<Value>>(LSDRadixSortHexL, 1000, 65535);

	std::cout << "### LSDRadixSort List : range [0..255] : tam 10000 ###" << std::endl;
	ejecutarFuncion<std::list<Value>>(LSDRadixSortHexL, 10000, 255);

	std::cout << "### LSDRadixSort List : range [0..65535] : tam 10000 ###" << std::endl;
	ejecutarFuncion<std::list<Value>>(LSDRadixSortHexL, 10000, 65535);

	std::cout << "### LSDRadixSort List : range [0..255] : tam 100000 ###" << std::endl;
	ejecutarFuncion<std::list<Value>>(LSDRadixSortHexL, 100000, 255);

	std::cout << "### LSDRadixSort List : range [0..65535] : tam 100000 ###" << std::endl;
	ejecutarFuncion<std::list<Value>>(LSDRadixSortHexL, 100000, 65535);
    
	return 0;
}

/**********************************************************************/ /**
 *
 *  Generates an array of Values with random values and any others
  *
  *
  * @param [out] vec Vector of Values to fill
  * @param [in] gen Random number generator.
 *
 */ /**********************************************************************/
template <typename T>
void generateRandom(T &vec, std::mt19937& gen, const int KEY_MIN, const int KEY_MAX) {
	std::uniform_int_distribution<> d(KEY_MIN, KEY_MAX);
	
	for (auto it = vec.begin(); it != vec.end(); it++) {
		*it = { (unsigned int)d(gen), (char*)"valor random" };
	}
}

/**********************************************************************/ /**
 *
 *  Call the sort function 1000 times with the ordered range and size
  *
  *
  * @param [in] lambda function to call to sort
  * @param [in] size size of the vector or list
  * @param [in] range range of the vector or list
 *
 */ /**********************************************************************/
template <typename T>
void ejecutarFuncion(std::function<void(T&, const unsigned int&)> lambda, const unsigned &size, const unsigned &range) {

	T vec(size), aux(size);
	std::random_device rd;
	std::mt19937 gen(rd());
	generateRandom(vec, gen, 0, range);

	Cronometro c;

	for (int i = 0; i < 1000; i++)
	{
		aux = vec;
		lambda(aux, range);
	}
}