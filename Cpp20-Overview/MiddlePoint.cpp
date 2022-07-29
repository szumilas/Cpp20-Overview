#include <cstdint>
#include <limits>
#include <numeric>
#include <iostream>

//Calculate the midpoint of two integers safely (without overflow).

namespace MiddlePoint
{
	void foo()
	{
        std::uint32_t a = std::numeric_limits<std::uint32_t>::max();
        std::uint32_t b = std::numeric_limits<std::uint32_t>::max() - 2;

        std::cout << "a: " << a << '\n'
            << "b: " << b << '\n'
            << "Incorrect (overflow and wrapping): " << (a + b) / 2 << '\n'
            << "Correct: " << std::midpoint(a, b) << "\n";

        auto text = "0123456789";
        std::cout << *std::midpoint(text + 2, text + 4);
	}
}

/*
a: 4294967295
b: 4294967293
Incorrect (overflow and wrapping): 2147483646
Correct: 4294967294
3
*/