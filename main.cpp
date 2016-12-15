#include <iostream>

#include "pair.h"

#define TEST(X) \
if ((X)) { \
    std::cout << "PASS        " << __FUNCTION__ << std::endl;\
} else {\
    std::cout << "FAILED      " << __FUNCTION__ << std::endl;\
}

void default_constructor()
{
    eda::pair<int, int> curr;

    TEST(curr.first == 0 && curr.second == 0);
}

void default_constructor_pointer()
{
    eda::pair<int*, int*> curr;

    TEST(curr.first == nullptr && curr.second == nullptr);
}

void test()
{
    default_constructor();
    default_constructor_pointer();
}

int main()
{
    test();
    return 0;
}
