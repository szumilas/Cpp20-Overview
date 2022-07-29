#include <set>
#include <iostream>

// Associative containers such as sets and maps have a contains member function, which can be used
// instead of the "find and check end of iterator" idiom.

namespace CheckIfContainerHasElement
{
	void foo()
	{
		std::set<int> s{ 1, 2, 3 };

		if (s.contains(8))
		{
			std::cout << "set contains 8\n";
		}
	}
}