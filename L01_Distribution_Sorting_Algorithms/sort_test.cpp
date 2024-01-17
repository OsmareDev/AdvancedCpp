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
constexpr unsigned int SIZE_V = 20;

/*
 * Prototypes of the functions used,
 * implemented after main()
 */
template <typename T>
void generateRandom(T &vec, std::mt19937& gen, const int KEY_MIN, const int KEY_MAX);

/*
 * Main
 */
int main() {
	std::vector<Value> vec(SIZE_V), vec2(SIZE_V), aux(SIZE_V);
	std::list<Value> l(SIZE_V), l2(SIZE_V);
	std::random_device rd;
	std::mt19937 gen(rd());

	generateRandom(vec, gen, KEY_MIN1, KEY_MAX1);
	generateRandom(vec2, gen, KEY_MIN2, KEY_MAX2);
	generateRandom(l, gen, KEY_MIN1, KEY_MAX1);
	generateRandom(l2, gen, KEY_MIN2, KEY_MAX2);
	
	// Case 1 using CounterSort from 0 to 255
	aux = vec;
	std::cout << "CountSort [0-" << KEY_MAX1 << "]" << std::endl;
	countSort(aux, KEY_MAX1);
	for (Value x : aux)
		x.show();

	std::cout << std::endl;

	// Case 2 using CounterSort from 0 to 65535
	aux = vec2;
	std::cout << "CountSort [0-" << KEY_MAX2 << "]" << std::endl;
	countSort(aux, KEY_MAX2);
	for (Value x : aux)
		x.show();

	std::cout << std::endl;


	// Case 3 using RadixSort from 0 to 255
	aux = vec;
	std::cout << "RadixSort [0-" << KEY_MAX1 << "]" << std::endl;
	LSDRadixSort(aux, KEY_MAX1);
	for (Value x : aux)
		x.show();

	std::cout << std::endl;

	// Case 4 using RadixSort from 0 to 65535
	aux = vec2;
	std::cout << "RadixSort [0-" << KEY_MAX2 << "]" << std::endl;
	LSDRadixSort(aux, KEY_MAX2);
	for (Value x : aux)
		x.show();

	std::cout << std::endl;

	// Case 5 using RadixSort<Lists> from 0 to 255
	std::cout << "RadixSort<List> [0-" << KEY_MAX1 << "]" << std::endl;	
	LSDRadixSort(l, KEY_MAX1);
	for (Value x : l)	{
		x.show();
	}    
    

	// Case 6 using RadixSort<Lists> from 0 to 65535
	std::cout << "RadixSort<List> [0-" << KEY_MAX2 << "]" << std::endl;	
	LSDRadixSort(l2, KEY_MAX2);
	for (Value x : l2)	{
		x.show();
	}    
    
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
		*it = { (unsigned int)d(gen), (char*)"random value" };
	}
}
