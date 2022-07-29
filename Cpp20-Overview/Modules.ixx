export module ModuleFoo;   // module declaration
import <iostream>;         // import declaration

namespace Modules
{
    export void foo()  // exported function
    {
        std::cout << "imported function!";
    }

    void boo()         // not exported function
    {
        std::cout << "noooooo!";
    }
}