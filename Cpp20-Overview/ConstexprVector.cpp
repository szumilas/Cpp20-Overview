#include <vector>
#include <algorithm>

// It is not possible to have constexpr vector, but it is possible to use vector in constexpr context.

namespace ConstexprVector
{
	constexpr int boo()
	{
		std::vector<int> v;
		v.push_back(5);
		v.push_back(7);
		v.push_back(1);

		std::sort(v.begin(), v.end());

		return v[0];

	}

	void foo()
	{
		constexpr auto x = boo(); // constepxr x = 1

		//constexpr std::vector<int> v; // doesn't compile
	}

}