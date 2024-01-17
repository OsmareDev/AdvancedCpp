#include <iostream>
#include <array>

template<size_t x>
int add(const std::array<int, x>&);

int main()
{
	std::array<int, 4> v = { 2,4,6,8 };
	int s = add(v);
	std::cout << s << std::endl;
}

template<size_t x>
int add(const std::array<int, x>& a) {
	int sumator = 0;

	for (size_t i = 0; i < x; i++) {
		sumator += a[i];
	}

	return sumator;
}