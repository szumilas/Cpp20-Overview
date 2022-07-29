#include <vector>
#include <iostream>

namespace RangeBasedForLoopWithInitializers
{
	void foo()
	{
        for (auto vec = std::vector{ 1, 2, 3 }; auto v : vec)
        {
            std::cout << v << " ";
        }
        std::cout << "\n";

        for (auto x = 5; auto e : { 1, 2, 3 })
        {
            std::cout << e * x << " ";
        }
        std::cout << "\n";

        for (std::string str = "Hello World"; auto c : str)
        {
            std::cout << c << " ";
        }
	}
}

// Output:
// 1 2 3
// 5 10 15
// H e l l o   W o r l d