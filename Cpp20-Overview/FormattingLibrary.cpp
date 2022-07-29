#include <format>
#include <iostream>

// The text formatting library offers a safe and extensible alternative to the printf family of functions.

namespace FormattingLibrary
{
	void foo()
	{
		std::string message = std::format("Name: {}, Surname: {}, Age: {}", "Jan", "Nowak", 50);
		std::cout << message;
	}
}

// output:
// Name: Jan, Surname: Nowak, Age: 50