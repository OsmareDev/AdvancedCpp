#include <vector>
#include <algorithm>
#include <iostream>

int main() {
	std::vector<int> c = { 1,2,3 };
	auto add5 = [](int& a) {
		a += 5;
	};
	std::for_each(c.begin(), c.end(), add5);
	std::for_each(c.begin(), c.end(), [](int& n) {std::cout << n << std::endl; });	
}