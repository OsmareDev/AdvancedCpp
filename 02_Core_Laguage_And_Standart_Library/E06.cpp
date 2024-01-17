#include <iostream>

long double operator"" _kg(unsigned long long peso) {
	return peso * 1000.;
}

long double operator"" _g(unsigned long long peso) {
	return peso;
}

long double operator"" _mg(unsigned long long peso) {
	return peso / 1000.;
}

int main() {
	// weight is in grams
	float weight = 1_kg + 15_g + 30_mg;

	std::cout << weight << std::endl;
}