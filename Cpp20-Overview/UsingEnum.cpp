#include <string>

// Bring an enum's members into scope to improve readability.

namespace UsingEnum
{
    enum class Color
    {
        red,
        green,
        blue,
        orange,
    };

    std::string ColorToString(Color color)
    {
        using enum Color;

        switch (color)
        {
        case red   : return "red";
        case green : return "green";
        case blue  : return "blue";
        case orange: return "orange";
        default    : return "";
        }
    }

    void foo()
    {
        auto stringColor = ColorToString(Color::red);
    }
}