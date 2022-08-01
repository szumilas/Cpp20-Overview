#include <iostream>

namespace ThreeWayComparisonOperator
{

	struct MyInt
	{
		int value;
		std::string something;

		auto operator<=>(const MyInt& rhs) const
		{
			return value <=> rhs.value;
		}
	};


	void foo()
	{
		MyInt x{ 5 };
		MyInt y{ 6 };
		std::cout << (x > y) << " ";
		std::cout << (x >= y) << " ";
		std::cout << (x < y) << " ";
		std::cout << (x <= y) << " ";
	}
}

/*
0 0 1 1
*/