// Virtual functions can now be constexpr and evaluated at compile-time. constexpr virtual functions can override non-constexpr
// virtual functions and vice-versa.

namespace ConstexprVirtual
{
	struct Animal
	{
		constexpr virtual bool GetNoOfLegs() const { return 0; }
	};

	struct Dog : public Animal
	{
		constexpr bool GetNoOfLegs() const override { return 4; }
	};

	struct Snake : public Animal
	{
		constexpr bool GetNoOfLegs() const override { return 0; }
	};

	bool constexpr CompareAnimals(const Animal& animal1, const Animal& animal2)
	{
		return animal1.GetNoOfLegs() > animal2.GetNoOfLegs();
	}

	void foo()
	{
		constexpr Dog dog;
		constexpr Snake snake;
		constexpr auto result1 = CompareAnimals(dog, snake); // result1 = true
		constexpr auto result2 = CompareAnimals(snake, dog); // result2 = false
	}
}

//https://www.cppstories.com/2021/constexpr-virtual/