#include <span>
#include <vector>
#include <array>
#include <iostream>

//A span is a view (i.e. non-owning) of a container providing bounds-checked access to a contiguous group of elements.

namespace spanCpp
{
	void boo(std::span<int> elements)
	{
		for (const auto& element : elements)
		{
			std::cout << element << " ";
		}
		std::cout << std::endl;
	}

	void foo()
	{
		std::vector<int> v{ 1, 75, 55, 184 };
		std::array<int, 3> a{ -8, 4, 22 };
		int t[] = { 8, 1, -2 };

		boo(v);
		boo(a);
		boo(t);
	}
}

// prints:
// 1 75 55 184
// - 8 4 22
// 8 1 - 2