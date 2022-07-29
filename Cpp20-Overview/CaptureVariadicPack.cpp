#include <memory>
#include <iostream>

// Capture parameter packs by value

namespace CaptureVariadicPack
{

	template<typename ...T>
	void boo(T&... args)
	{
		auto lambda = [...copyArgs = args]()
		{
			((std::cout << copyArgs << " "), ...);
		};

		((args = 0), ...);
		((std::cout << args << " "), ...); // prints: 0 0 0

		lambda(); // prints: 1 2 3
	}

	void foo()
	{
		int a = 1, b = 2, c = 3;
		boo(a, b, c);
	}
}