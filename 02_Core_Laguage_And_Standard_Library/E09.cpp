#include <vector>
#include <iostream>
#include <unordered_map>

std::unordered_map<std::string, int> func(std::vector<std::string> v) {
	std::unordered_map<std::string, int> map;

	for (std::string s : v)
	{
		if (!map.emplace(std::make_pair(s, 1)).second)
			map[s]++;
	}

	return map;
}

int main() {
	std::vector<std::string> v = { "hola","adios","hola","dedo" };

	std::unordered_map<std::string, int> map = func(v);

	for (auto m : map) {
		std::cout << "La palabra: " << m.first << " ha salido " << m.second << " veces \n";
	}
}