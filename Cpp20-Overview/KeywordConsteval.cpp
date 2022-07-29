namespace KeywordConsteval
{
	consteval int sqr(int a)
	{
		return a * a;
	}

	void foo()
	{
		int x1 = sqr(5);

		const int a = 5;
		int x2 = sqr(a);

		int b = 5;
		//int x3 = sqr(b); // compile error
	}
}

// Consteval functions are similar to constexpr functions, but they must produce a constant.
// These functions are called immediate functions.