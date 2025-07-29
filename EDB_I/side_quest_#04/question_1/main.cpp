#include <iostream>
#include <array>

#include "local_minimum_in_an_array.cpp"

int main()
{
    std::array<value_type, 9> v = {10, 8, 6, 4, 3, 5, 7, 9, 7};
    std::array<value_type, 9> v2 = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    std::array<value_type, 9> v3 = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout << "Testing local_minimum_in_an_array algorithm...\n";

    //=== Test #1
    auto result = local_minimum_in_an_array(begin(v), end(v));

    if (result == end(v))
    {
        std::cout << "No local minimum found\n";
    }
    else
    {
        std::cout << "Local minimum found at index " << result - begin(v) << " with value " << *result << std::endl;
    }

    //=== Test #2
    auto result2 = local_minimum_in_an_array(begin(v2), end(v2));

    if (result2 == end(v2))
    {
        std::cout << "No local minimum found\n";
    }
    else
    {
        std::cout << "Local minimum found at index " << result2 - begin(v2) << " with value " << *result2 << std::endl;
    }

    //=== Test #3
    auto result3 = local_minimum_in_an_array(begin(v3), end(v3));

    if (result3 >= end(v3))
    {
        std::cout << "No local minimum found\n";
    }
    else
    {
        std::cout << "Local minimum found at index " << result3 - begin(v3) << " with value " << *result3 << std::endl;
    }
}