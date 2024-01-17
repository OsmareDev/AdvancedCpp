/*
6. Write a C++ program for calculating the following function using dynamic programming.

int f(int n)
{
    if(n == 0)
        return 1;
    else
        return f(n-1) + f(n/2);
}
*/

#include <vector>
#include <iostream>

int f(int n) {
    std::vector<int> v(n+1);
    if (n == 0)
        return 1;
    else {
        v[0] = 1;

        for  (int i = 1; i <= n; ++i){
            v[i] = v[i-1] + v[i/2];
        }
    }

    return v[n];
}

int main() {

    std::cout << f(3) << std::endl;

    return 0;
}