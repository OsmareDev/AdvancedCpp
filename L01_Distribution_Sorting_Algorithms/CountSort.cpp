#include "CountSort.h"
#include "Value.h"

/**********************************************************************/ /**
 *
 *  CountSort sorting algorithm
  *
  * @pre The indices do not exceed KEY_MAX
  *
  * @param [in,out] vec Vector to sort, contains the keys and character strings
  *
  * @param [in] KEY_MAX Maximum of the key of the elements to be sorted,
  * range [0, KEY_MAX]
 *
 */ /**********************************************************************/
void countSort(std::vector<Value> &vec, const unsigned int& KEY_MAX){
	std::vector<int> aux(KEY_MAX+1);
	std::vector<Value> v2(vec.size());
    
	for (Value p : vec)
	{
		aux[p.key]++;
	}

	for (unsigned int i = 1; i <= KEY_MAX; i++) {
		aux[i] += aux[i - 1];
	}
	
	for (int i = (int)vec.size()-1; i >= 0; i--) {
		v2[aux[vec[i].key]-1] = vec[i];
		aux[vec[i].key]--;
	}
 
	vec = v2;
}
