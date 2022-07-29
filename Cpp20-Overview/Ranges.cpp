#include <ranges>
#include <vector>
#include <array>
#include <algorithm>
#include <iostream>

namespace Ranges
{
	void doo()
	{
        std::vector<int> input = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        auto divisible_by_three = [](const int n) {return n % 3 == 0; };
        auto square = [](const int n) {return n * n; };

        auto view1 = input | std::views::filter(divisible_by_three) | std::views::transform(square);

        for (const auto& e : view1)
        {
            std::cout << e << " ";
        }

        std::cout << std::endl;

        auto view2 = input | std::views::filter(square) | std::views::transform(divisible_by_three);

        for (const auto& e : view2)
        {
            std::cout << e << " ";
        }
	}

    void boo()
    {
        std::vector<int> v = { 2, 3, 1, 5, 4 };
        std::ranges::sort(v);

        for (const auto& e : v)
        {
            std::cout << e << " ";
        }
    }

    void foo()
    {
        std::vector<double> v = { -5.14, 84, -15.21, 2.44, 5 };

        for (const auto& e : v | std::views::filter([](const auto x) { return x > 0; }))
        {
            std::cout << e << " ";
        }
    }
}

/*
0 9 36 81
0 0 1 0 0 1 0 0 1 0
*/

/*
1 2 3 4 5
*/

/*
84 2.44 5
*/