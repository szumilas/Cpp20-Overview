#include <string>

// It is not possible to have constexpr string, but it is possible to use string in constexpr context.

namespace ConstexprString
{
	constexpr bool boo()
	{
		std::string s;
		s.append("Filename");
		s.append(".txt");

		return s.find('.') != std::string::npos;
	}

	void foo()
	{
		constexpr auto x = boo(); // bool x = true

		//constexpr std::string s; // doesn't compile
	}
}