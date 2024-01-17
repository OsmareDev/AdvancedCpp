#ifndef VALUE_H_
#define VALUE_H_

#include <iostream>
#include <cstring>
#include <vector>
#include <list>

/**
 * Type array char String: auxiliary type to construct the character string other
 */
typedef char Cadena[100];

/**
 * Values registry where the key and the value to be sorted later are stored, implements a constructor
  * to assign values to attributes correctly
 */
struct Value
{
	Cadena other;
	unsigned int key;

	Value() = default;
	Value(unsigned int key, Cadena other)
	{
		this->key = key;
		strcpy(this->other, other);
	}

	bool operator < (const Value& v) const
	{
		return key < v.key;
	}

	void show() { std::cout << key << " : " << other << std::endl; }
};

#endif