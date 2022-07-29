#include <vector>
#include <list>

namespace TemplateParameterForLambdas
{
	void foo()
	{
		auto lambdaCpp17 = [](auto x, auto y) { return x + y; };
		auto lambdaCpp20 = []<typename T>(T x, T y) { return x + y; };

		auto resultCpp17 = lambdaCpp17(true, 5); // resultCpp17 = 6
		//auto resultCpp20 = lambdaCpp20(true, 5); // compilation error

		auto lambdaWithContainerCpp17 = [](const auto& container) { return container.size(); };
		auto lambdaWithContainerCpp20 = []<typename T>(const std::vector<T>& container) { return container.size(); };

		auto containerResultCpp17 = lambdaWithContainerCpp17(std::list{1, 2, 3}); // containerResultCpp17 = 3
		//auto containerResultCpp20 = lambdaWithContainerCpp20(std::list{ 1, 2, 3 }); // compilation error
	}

}