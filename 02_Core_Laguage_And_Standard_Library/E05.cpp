#include <iostream>

int main() {
	enum m : unsigned char { January = 1, February, March, April, May, Juny, July, August, September, October, November, December };
	m example = April;

	switch (example) {
	case January:
		std::cout << "today is January" << std::endl;
		break;
	
	case February:
		std::cout << "today is February" << std::endl;
		break;

	case March:
		std::cout << "today is March" << std::endl;
		break;

	case April:
		std::cout << "today is April" << std::endl;
		break;

	case May:
		std::cout << "today is May" << std::endl;
		break;

	case Juny:
		std::cout << "today is Juny" << std::endl;
		break;

	case July:
		std::cout << "today is July" << std::endl;
		break;

	case August:
		std::cout << "today is August" << std::endl;
		break;

	case September:
		std::cout << "today is September" << std::endl;
		break;

	case October:
		std::cout << "today is October" << std::endl;
		break;

	case November:
		std::cout << "today is November" << std::endl;
		break;

	case December:
		std::cout << "today is December" << std::endl;
		break;
	}

	if (example == 4) {
		std::cout << "cuidado con las bromas el dia 1" << std::endl;
	}
}