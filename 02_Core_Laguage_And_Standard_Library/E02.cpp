#include <vector>
#include <list>
#include <iostream>

int main() {
	std::vector<std::list<double>> v;

	std::list<double> a, b;
	a.push_back(1.22);
	a.push_back(1.33);

	b.push_back(2.33);
	b.push_back(1.734);

	v.push_back(a);
	v.push_back(b);

	int cont_v = 0;
	for (auto i : v) {
		std::cout << "Elemento: " << cont_v << " del vector contiene la siguiente lista:" << std::endl;
		int cont = 0;
		for (auto j = i.begin(); j != i.end(); j++) {
			std::cout << " Elemento: " << cont << " de la lista: " << *j << std::endl;
			cont++;
		}
		cont_v++;
	}
}