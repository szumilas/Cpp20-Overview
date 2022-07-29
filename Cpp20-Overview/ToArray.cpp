#include <array>

//Converts the given object to a std::array.

namespace ToArray
{
	void foo()
	{
		auto x1 = std::to_array("foo"); // returns `std::array<char, 4>`
		auto x2 = std::to_array<int>({ 1, 2, 3 }); // returns `std::array<int, 3>`

		int a[] = { 1, 2, 3 };
		auto x3 = std::to_array(a); // returns `std::array<int, 3>`
	}
}