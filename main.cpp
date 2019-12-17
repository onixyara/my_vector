#include "vector.hpp"
#include <vector>
#include <iostream>

int			main()
{
	Vector<int> arr;
	Vector<int>	arr2;

	arr.push_back(2);
	arr.push_back(2);
	arr.push_back(2);
	arr2 = std::move(arr);

	std::cout << "Arr2 = " << arr2.size() << " Arr = " << arr.size() << std::endl;

	return 0;
}