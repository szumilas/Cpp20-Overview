
// Implicitly capturing this in a lambda capture using [=] is now deprecated;
// prefer capturing explicitly using [=, this] or [=, *this].

namespace DeprecateImplicitCaptureOfThis
{
	struct S
	{
		int boo()
		{
			//return [=]() { return value; }(); // allowed in C++17, but not in C++20

			return [=, *this]() { return value; }();
		}

		int value = 0;
	};

	void foo()
	{
		S s;
		s.boo();
	}
}