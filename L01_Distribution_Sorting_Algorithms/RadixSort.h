#ifndef RADIX_SORT_H_
#define RADIX_SORT_H_

// #include <iostream>
#include <vector>
#include "Value.h"

void LSDRadixSort(std::vector<Value>& v, const unsigned int& KEY_MAX);
void LSDRadixSort(std::list<Value>& v, const unsigned int& KEY_MAX);
void flatVect(std::vector<Value> &v, const std::vector<std::vector<Value>> &bucket);
int Digit(const Value& v, const int& i);

#endif