#include "vector.hpp"
#include <vector>
#include <iostream>

struct A
{
	A(){ std::cout << "constructor\n";}
	~A() {std::cout << "destructor\n";}
};

int			main()
{
	std::vector<int> abs;
	abs.max_size();

	Vector<A>	vec;
	A a;
	vec.erase(0);
	return 0;
}