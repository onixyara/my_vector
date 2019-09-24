#include "vector.hpp"
//#include <vector>
#include <iostream>

struct A
{
	A(){ std::cout << "constructor\n";}
	~A() {std::cout << "destructor\n";}
};

int			main()
{

	Vector<A>	vec;
	A a;
	vec.erase(0);
	while(1)
	{}
	return 0;
}