#include <vector>
#include "supp.cpp"

unsigned search_1(std::vector<int>& v, int x);
unsigned search_2(std::vector<int>& v, int x);

int main() {
    std::vector<int> v = {1,2,34,5,6,7,8,9,0};
    int n = 6;

    tryFunc(search_1, v, n);
    tryFunc(search_2, v, n);
}

// Return the position of the element.
// Out of bound if the element doesn’t exist.
// 0.0205766 s
unsigned search_1(std::vector<int>& v, int x)
{
    unsigned pos = 0;
    while(pos < v.size() && v[pos] != x)
        pos++;
    return pos;
}

// 0.0113214 s
unsigned search_2(std::vector<int>& v, int x)
{
    unsigned n = v.size();
    for (unsigned pos = 0; pos < n; ++pos){
        if (v[pos] == x){
            return pos;
        }
    }

    return -1;
}