#include <iostream>
#include <vector>

// likely and unlikely attributes provide a hint to the optimizer that the labelled statement
// has a high probability of being executed.

namespace NewAttributes
{
    void foo()
    {
        srand(time(0));

        std::vector<int> v;

        for (int q = 0; q < 10'000'000; ++q)
        {
            v.push_back(rand() % 100);
        }

        int biggerThan95 = 0;

        for (int q = 0; q < 10'000'000; ++q)
        {
            switch (v[q])
            {
            case 96: [[unlikely]] biggerThan95++; break;
            case 97: [[unlikely]] biggerThan95++; break;
            case 98: [[unlikely]] biggerThan95++; break;
            case 99: [[unlikely]] biggerThan95++; break;
            default: [[likely]] break;
            }
        }
    }
}