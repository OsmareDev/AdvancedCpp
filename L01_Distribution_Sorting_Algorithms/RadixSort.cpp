#ifndef RADIX_SORT_H_
#define RADIX_SORT_H_

// #include <iostream>

#include "RadixSort.h"
#include "Value.h"
#include <cmath>
#include <vector>


/**********************************************************************/ /**
 *
 *  Returns the digit in position i of a value
  *
  *
  * @param [in,out] v Vector of Values to sort
  * @param [in] KEY_MAX Maximum value that the key of the values can have
 *
 */ /**********************************************************************/
int Digit(const Value& v, const int& i) {
    return (v.key / (int)pow(10, i)) % 10;
}


/**********************************************************************/ /**
 *
 *  Converts a vector of vectors to a flat vector+
  *
  *
  * @param [in,out] v Data type where the vector of values is stored
  * @param [in] bucket Vector of vectors of values
 *
 */ /**********************************************************************/
template <typename T>
void flatVect(T &v, const std::vector<T> &bucket) {
  v.clear();
  for (const T& buck: bucket) {
      v.insert(v.end(), buck.begin(), buck.end());
  }
}

/**********************************************************************/ /**
 *
 *  Sort a vector using RadixSort
  *
  *
  * @param [in,out] v Vector of Values to sort
  * @param [in] KEY_MAX Maximum value that the key of the values can have
 *
 */ /**********************************************************************/
void LSDRadixSort(std::vector<Value>& v, const unsigned int& KEY_MAX)
{
  // 10 buckets [0-9]
  std::vector<std::vector<Value>> bucket(10);

  int limit = (int)log10(KEY_MAX);
  for (int i=0; i <= limit; i++)
  {
    for (int j=0; j <= 9; j++)
    {
      bucket[j].clear();
    }

    for (size_t j=0; j < v.size(); j++)
    {
      int digit = Digit(v[j], i);
      bucket[digit].push_back(v[j]);
    }

// concatenate buckets into v
    flatVect(v, bucket);
  }
}

/**********************************************************************/ /**
 *
 *  Sort a list using RadixSort
  *
  *
  * @param [in,out] v List of Values to sort
  * @param [in] KEY_MAX Maximum value that the key of the values can have
 *
 */ /**********************************************************************/
void LSDRadixSort(std::list<Value>& l, const unsigned int& KEY_MAX)
{
  // 10 buckets [0-9]
  std::vector<std::list<Value>> bucket(10);
  
  int limit = (int)log10(KEY_MAX);
  for (int i=0; i <= limit; i++)
  {
    for (int j=0; j <= 9; j++)
    {
      bucket[j].clear();
    }


    while(l.size() > 0)
    {
      //std::cout << "value: " << it->key << std::endl;
      int digit = Digit(*l.begin(), i);
      // splice list l into bucket[digit]
      bucket[digit].splice(bucket[digit].end(), l, l.begin());
    }
    
    // concatenate buckets into l
    flatVect(l, bucket);
    
  }
}


#endif