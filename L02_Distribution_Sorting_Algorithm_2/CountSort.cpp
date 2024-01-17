#include "CountSort.h"
#include "Value.h"

/**********************************************************************/ /**
 *
 *  CountSort sorting algorithm
   *
   * @pre Indexes do not exceed KEY_MAX
   *
   * @param [in,out] vec Vector to sort, contains the keys and character strings
   *
   * @param [in] KEY_MAX Maximum key of the elements to be sorted,
   * range [0, KEY_MAX]
 *
 */ /**********************************************************************/
void countSort(std::vector<Value> &vec, const unsigned int& KEY_MAX){
	std::vector<int> aux(KEY_MAX+1);
	std::vector<Value> v2(vec.size());

	for (unsigned i = 0; i < vec.size(); i+=10)
	{
		aux[vec[i].key]++;
		aux[vec[i+1].key]++;
		aux[vec[i+2].key]++;
		aux[vec[i+3].key]++;
		aux[vec[i+4].key]++;

		aux[vec[i+5].key]++;
		aux[vec[i+6].key]++;
		aux[vec[i+7].key]++;
		aux[vec[i+8].key]++;
		aux[vec[i+9].key]++;
	}

	for (unsigned int i = 1; i <= KEY_MAX; i+=5) {
		aux[i    ] += aux[i - 1];
		aux[i + 1] += aux[i    ];
		aux[i + 2] += aux[i + 1];
		aux[i + 3] += aux[i + 2];
		aux[i + 4] += aux[i + 3];
	}
	
	for (int i = (int)vec.size()-1; i >= 0; i-=10) {
		v2[aux[vec[i].key]-1] = vec[i];
		aux[vec[i].key]--;

		v2[aux[vec[i-1].key]-1] = vec[i-1];
		aux[vec[i-1].key]--;

		v2[aux[vec[i-2].key]-1] = vec[i-2];
		aux[vec[i-2].key]--;

		v2[aux[vec[i-3].key]-1] = vec[i-3];
		aux[vec[i-3].key]--;

		v2[aux[vec[i-4].key]-1] = vec[i-4];
		aux[vec[i-4].key]--;

		v2[aux[vec[i-5].key]-1] = vec[i-5];
		aux[vec[i-5].key]--;

		v2[aux[vec[i-6].key]-1] = vec[i-6];
		aux[vec[i-6].key]--;

		v2[aux[vec[i-7].key]-1] = vec[i-7];
		aux[vec[i-7].key]--;

		v2[aux[vec[i-8].key]-1] = vec[i-8];
		aux[vec[i-8].key]--;

		v2[aux[vec[i-9].key]-1] = vec[i-9];
		aux[vec[i-9].key]--;
	}
 
	vec = std::move(v2);
}
