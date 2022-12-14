#include <numbers>

//<number> - numeric library. The C++ numerics library includes common mathematical functions and types.

namespace numbersCpp20
{
	constexpr auto a = std::numbers::pi;    //double a = 3.14159...
	constexpr auto b = std::numbers::e;     //double b = 2.71828...

	constexpr auto c = std::numbers::sqrt2; //double c = 1.41421...
	constexpr auto d = std::numbers::ln2;   //double d = 0.69314...
	constexpr auto e = std::numbers::ln10;  //double e = 2.30258...
}