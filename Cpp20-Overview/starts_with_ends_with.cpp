#include <iostream>

// Strings (and string views) now have the starts_with and ends_with member
// functions to check if a string starts or ends with the given string.

namespace starts_with_ends_with
{

	void foo()
	{
		std::string filename = "C:/Windows/Document.txt";

		if (filename.ends_with(".txt"))
		{
			std::cout << "txt file\n";
		}

		if (filename.starts_with("C:/Windows/"))
		{
			std::cout << "file is in C:/Windows/ directory\n";
		}
	}
}