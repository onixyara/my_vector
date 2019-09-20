#include "vector.hpp"

int			main()
{
	Vector<int>	vec;

	vec.push_back(6);
	vec.push_back(6);
	vec.push_back(6);
	vec.push_back(6);
	vec.push_back(6);
	vec.push_back(6);
	vec.push_back(6);
	vec.push_back(6);
	vec.push_back(6);
	vec.push_back(6);
	vec.push_back(6);
	vec.push_back(6);
	vec.push_back(6);
	vec.push_back(6);
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	return 1;
}