#include <source_location>
#include <iostream>

// The source_location class represents certain information about the source code, such as file names,
// line numbers, and function names. Previously it was necessary to use predefined macros
// like __LINE__ and __FILE__. The source_location class provides a better alternative.

namespace SourceLocation
{
	void log(std::source_location location = std::source_location::current())
	{
		std::cout << "file: " << location.file_name()
			<< "(" << location.line() << ":" << location.column() << ") `"
			<< location.function_name() << '\n';
	}

	int boo()
	{
		log();
		return 0;
	}

	void foo()
	{
		log();
		boo();
	}
}

// Possible output:
// file: C:\FileName.cpp(21:3) `foo
// file: C:\FileName.cpp(15:3) `boo