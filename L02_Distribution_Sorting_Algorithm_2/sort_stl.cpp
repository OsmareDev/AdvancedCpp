/**********************************************************/ /**
 *
 * @file sort_stl.cpp
 *
 * Compare times with the C++ Sort library.
 *
 * @date 25-10-2022
 */ /**************************************************************************/

#include <iostream>
#include <random>
#include <algorithm>

#include "Value.h"
#include "Crono.cpp"

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
void ejecutarFuncionV(const unsigned &size, const unsigned &range);
void ejecutarFuncionL(const unsigned &size, const unsigned &range);

int main() {

  	std::cout << "\n\n######## sort_test.cpp ########" << std::endl;

	std::cout << "### Sort STL Vector : range [0..255] : tam 1000 ###" << std::endl;
	ejecutarFuncionV(1000, 255);

	std::cout << "### Sort STL Vector : range [0..65535] : tam 1000 ###" << std::endl;
	ejecutarFuncionV(1000, 65535);

	std::cout << "### Sort STL Vector : range [0..255] : tam 10000 ###" << std::endl;
	ejecutarFuncionV(10000, 255);

	std::cout << "### Sort STL Vector : range [0..65535] : tam 10000 ###" << std::endl;
	ejecutarFuncionV(10000, 65535);

	std::cout << "### Sort STL Vector : range [0..255] : tam 100000 ###" << std::endl;
	ejecutarFuncionV(100000, 255);

	std::cout << "### Sort STL Vector : range [0..65535] : tam 100000 ###" << std::endl;
	ejecutarFuncionV(100000, 65535);

	// --------------------------------

	std::cout << "### Sort STL List : range [0..255] : tam 1000 ###" << std::endl;
	ejecutarFuncionL(1000, 255);

	std::cout << "### Sort STL List : range [0..65535] : tam 1000 ###" << std::endl;
	ejecutarFuncionL(1000, 65535);

	std::cout << "### Sort STL List : range [0..255] : tam 10000 ###" << std::endl;
	ejecutarFuncionL(10000, 255);

	std::cout << "### Sort STL List : range [0..65535] : tam 10000 ###" << std::endl;
	ejecutarFuncionL(10000, 65535);

	std::cout << "### Sort STL List : range [0..255] : tam 100000 ###" << std::endl;
	ejecutarFuncionL(100000, 255);

	std::cout << "### Sort STL List : range [0..65535] : tam 100000 ###" << std::endl;
	ejecutarFuncionL(100000, 65535);

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
void ejecutarFuncionV(const unsigned &size, const unsigned &range) {

	std::vector<Value> vec(size), aux(size);
	std::random_device rd;
	std::mt19937 gen(rd());
	generateRandom(vec, gen, 0, range);

	Cronometro c;

	for (int i = 0; i < 1000; i++)
	{
		aux = vec;
		std::sort(aux.begin(), aux.end());
	}
}

void ejecutarFuncionL(const unsigned &size, const unsigned &range) {

	std::list<Value> vec(size), aux(size);
	std::random_device rd;
	std::mt19937 gen(rd());
	generateRandom(vec, gen, 0, range);

	Cronometro c;

	for (int i = 0; i < 1000; i++)
	{
		aux = vec;
		aux.sort();
	}
}