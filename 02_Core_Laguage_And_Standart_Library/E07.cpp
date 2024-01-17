#include <list>
#include <forward_list>

int main() {
	std::list<int> l1 = { 1,2,3 };
	std::list<int> l2 = { -2,-1 };

	// a
	l1.insert(l1.begin(), 0);

	// b
	l1.push_back(4);

	// c
	l1.insert(l1.begin(), l2.begin(), l2.end());

	std::forward_list<int> l3 = { 1,2,3 };
	std::forward_list<int> l4 = { -2,-1 };

	// d
	l3.push_front(0);

	// e
	auto it = l3.before_begin();
	for (auto _ : l3)
	{
		it++;
	}

	l3.insert_after(it, 4);

	// f
	l3.insert_after(l3.before_begin(), l4.begin(), l4.end());
}