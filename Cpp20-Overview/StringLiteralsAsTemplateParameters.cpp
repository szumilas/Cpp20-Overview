#include <compare>
#include <algorithm>

namespace StringLiteralsAsTemplateParameters
{
    template<size_t N>
    struct StringLiteral
    {
        constexpr StringLiteral(const char(&str)[N])
        {
            std::copy_n(str, N, value);
        }

        constexpr bool operator==(const StringLiteral&) const = default;

        char value[N];
    };

    template<StringLiteral str1, StringLiteral str2>
    constexpr bool CompareString()
    {
        return str1 == str2;
    }

    void foo()
    {
        constexpr auto value1 = CompareString<"ABC", "ABC">(); // value = true;
        constexpr auto value2 = CompareString<"AAA", "BBB">(); // value = false;
        //constexpr auto value3 = CompareString<"ABC", "AAAA">(); // doesn't compile
    }
}

//https://ctrpeach.io/posts/cpp20-string-literal-template-parameters/