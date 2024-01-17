#include <utility>
#include <iostream>

const int MAX = 100;

class Stack
{
	int* v;
	int top;
	unsigned max_size;
public:
	Stack(unsigned size)
	{
		v = new int[size];
		max_size = size;
		top = -1;
	}

	// copy constructor
	Stack(const Stack& s) {
		max_size = s.max_size;
		v = new int[max_size];

		for (unsigned i = 0; i < max_size; i++)
			v[i] = s.v[i];

		top = s.top;
	}

	// move constructor
	Stack(Stack&& s)
	{
		max_size = s.max_size;

		top = s.top;
		s.top = -1;

		v = s.v;

		s.v = nullptr;
	}

	// normal asignment
	Stack& operator= (const Stack& s) {
		if (this != &s)
		{
			delete[] v;

			max_size = s.max_size;
			top = s.top;

			v = new int[max_size];
			for (unsigned i = 0; i < max_size; i++)
				v[i] = s.v[i];
		}

		return *this;
	}

	// move asignment
	Stack& operator=(Stack&& s) noexcept {
		if (this != &s)
		{
			delete[] v;

			max_size = s.max_size;

			top = s.top;
			s.top = -1;

			v = s.v;

			s.v = nullptr;
		}

		return *this;
	}
};
class Vector2
{
	int* v[MAX];
	unsigned size;
public:
	Vector2(unsigned t)
	{
		size = t;
		for (unsigned i = 0; i < MAX; i++)
			v[i] = new int[size];
	}

	// copy constructor
	Vector2(const Vector2& vec) {
		size = vec.size;

		for (int i = 0; i < MAX; i++) {
			v[i] = new int[size];
			for (unsigned j = 0; j < size; j++)
				v[i][j] = vec.v[i][j];
		}
	}

	// move constructor
	Vector2(Vector2&& v2)
	{
		size = v2.size;

		for (int i = 0; i < MAX; i++)
		{
			v[i] = v2.v[i];
			v2.v[i] = nullptr;
		}
	}

	// normal asignment
	Vector2& operator= (const Vector2& vec) {
		if (this != &vec)
		{
			for (int* i : v)
				delete[] i;

			size = vec.size;

			for (int i = 0; i < MAX; i++) {
				v[i] = new int[size];

				for (unsigned j = 0; j < size; j++)
					v[i][j] = vec.v[i][j];
			}
		}

		return *this;
	}

	// move asignment
	Vector2& operator=(Vector2&& vec) {
		if (this != &vec)
		{
			for (int i = 0; i < MAX; i++) {
				delete[] v[i];

				v[i] = vec.v[i];

				vec.v[i] = nullptr;
			}

			size = vec.size;
			vec.size = 0;
		}

		return *this;
	}
};

int main() {
	Stack s1(5);
	Vector2 v1(5);

	//copy constructors
	Stack s2(s1);
	Vector2 v2(v1);

	//move constructor
	Stack s3((Stack&&)s1);
	Vector2 v3((Vector2&&)v1);

	//copy assignment
	s1 = s2;
	v1 = v2;

	//move assignment
	s3 = std::move(s1);
	v3 = (Vector2&&)v1;
}