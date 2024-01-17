#include <vector>

const int MAX = 100;

class Stack
{
	int* v;
	int top;
	unsigned max_size;
public:
	Stack(unsigned size)
		: v{ new int[size] }, top{ -1 }, max_size{ size }
	{	}

	Stack(std::vector<int> vec)
		: v{ vec.data() }, top{ (int)vec.size() }, max_size{ (unsigned int)vec.size() }
	{	}

	Stack(const Stack& s) = delete;
};

int main() {

	Stack s({ 1,2,3,4 });


}