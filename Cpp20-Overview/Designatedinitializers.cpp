#include <iostream>

// C-style designated initializer syntax. Any member fields that are not explicitly listed
// in the designated initializer list are default-initialized.

namespace Designatedinitializers
{
	struct A
	{
		int x;
		int y;
	};

	struct B
	{
		int a = 99;
		int b;
	};

	void foo()
	{
		A a1;                      // x = undetermined, y = undetermined
		A a2{};                    // x = 0, y = 0
		A a3{ .y = 7 };            // x = 0, y = 7
		A a4{ .x = 20 };           // x = 20, y = 0
		//A a5{ .y = 7, .x = 20 }; // error, designators must appear in member declaration order of class
		A a6{ .x = 20, .y = 7 };   // x = 20, y = 7

		B b1;                      // a = 99, b = undetermined
		B b2{};                    // a = 99, b = 0
		B b3{ .a = 6 };            // a = 6, b = 0
		B b4{ .b = 11 };           // a = 99, b = 11
	}



	struct Point
	{
		int x;
		int y;
	};

	void doo(const Point& p)
	{
		std::cout << p.x << " " << p.y;
	}

	void boo()
	{
		doo({.x = 5, .y = 10});
	}

}

// https://en.cppreference.com/w/cpp/language/aggregate_initialization