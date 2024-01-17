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
*/
/**********************************************************************/
int Digit(const Value &v, const int &i)
{
  return (v.key / (int)pow(10, i)) % 10;
}

/**********************************************************************/ /**
*
*  Returns the digit in position i of a hexadecimal value
*
*
* @param [in,out] v Vector of Values to sort
* @param [in] KEY_MAX Maximum value that the key of the values can have
*
*/
/**********************************************************************/
int DigitHex(const Value& v, const int &i)
{
  // shift
  int aux = v.key;
  aux >>= 4*i;
  
  // mask
  return (aux & 0xF);
}


/**********************************************************************/ /**
*
*  Converts a vector of vectors to a flat vector+
*
*
* @param [in,out] v Data type where the vector of values is stored
* @param [in] bucket Vector of vectors of values
*
*/
/**********************************************************************/
void flatVect(std::vector<Value> &v, std::vector<std::vector<Value>> &bucket)
{
  v.clear();
  for (const std::vector<Value> &buck : bucket)
  {
    v.insert(v.end(), buck.begin(), buck.end());
  }
}

void flatVect(std::list<Value> &v, std::vector<std::list<Value>> &bucket)
{
  // move all elements from bucket to v
  // v.clear();
  // use splice to move elements from bucket to v
  for (std::list<Value> &buck : bucket)
  {
    v.splice(v.end(), buck);
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
*/
/**********************************************************************/
void LSDRadixSort(std::vector<Value> &v, const unsigned int &KEY_MAX)
{
  //  buckets [0-9]
  std::vector<std::vector<Value>> bucket(10);

  for (int i = 0; i <= 9; i++)
  {
    // for (int j=0; j <= 9; j++)
    // {
    //   bucket[j].clear();
    // }
    bucket[0].clear();
    bucket[1].clear();
    bucket[2].clear();
    bucket[3].clear();
    bucket[4].clear();
    bucket[5].clear();
    bucket[6].clear();
    bucket[7].clear();
    bucket[8].clear();
    bucket[9].clear();

    for (size_t j = 0; j < v.size(); j++)
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
*  Sort a list using RadixSort with hexadecimal
*
*
* @param [in,out] v List of Values to sort
* @param [in] KEY_MAX Maximum value that the key of the values can have
*
*/
/**********************************************************************/
void LSDRadixSort(std::list<Value> &l, const unsigned int &KEY_MAX)
{
  // 10 buckets [0-15]
  std::vector<std::list<Value>> bucket(10);

  for (int i = 0; i <= 9; i++)
  {
    // for (int j=0; j <= 9; j++)
    // {
    //   bucket[j].clear();
    // }

    while (l.size() > 0)
    {
      int digit = Digit(*l.begin(), i);
      // splice list l into bucket[digit]
      bucket[digit].splice(bucket[digit].end(), l, l.begin());
    }

    // concatenate buckets into l
    flatVect(l, bucket);
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
*/
/**********************************************************************/
void LSDRadixSortHexV(std::vector<Value> &v, const unsigned int &KEY_MAX)
{
  //  buckets [0-15]
  std::vector<std::vector<Value>> bucket(16); // 0-15 hexadecimal

  // number of digits that has the maximum value

  for (int i = 0; i <= 15; i++)
  {
    for (int j=0; j <= 15; j++)
    {
      bucket[j].clear();
    }

    for (size_t j = 0; j < v.size(); j++)
    {
      int digit = DigitHex(v[j], i);
      bucket[digit].push_back(v[j]);
    }

    // concatenate buckets into v
    flatVect(v, bucket);
  }
}


/**********************************************************************/ /**
*
*  Sort a list using RadixSort with hexadecimal
*
*
* @param [in,out] v List of Values to sort
* @param [in] KEY_MAX Maximum value that the key of the values can have
*
*/
/**********************************************************************/
void LSDRadixSortHexL(std::list<Value> &l, const unsigned int &KEY_MAX)
{
  // 10 buckets [0-15]
  std::vector<std::list<Value>> bucket(16);

  for (int i = 0; i <= 15; i++) // puede que haga falta un =
  {
    while (l.size() > 0)
    {
      int digit = DigitHex(*l.begin(), i);
      // splice list l into bucket[digit]
      bucket[digit].splice(bucket[digit].end(), l, l.begin());
    }

    // concatenate buckets into l
    flatVect(l, bucket);
  }
}

#endif