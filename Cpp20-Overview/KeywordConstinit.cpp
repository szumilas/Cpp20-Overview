
//Constinit guarantees compile time initialization of variables.

namespace KeywordConstinit
{
	constexpr auto consetxprValue = 5;
	constinit auto constinitValue = 5;

	constexpr void increment(int& x)
	{
		++x;
	}

	void foo()
	{
		//constexpr auto newVariable = constinitValue; // doesn't compile

		//increment(consetxprValue); // doesn't compile
		increment(constinitValue);
	}
}