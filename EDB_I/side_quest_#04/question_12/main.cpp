#include <iostream>
#include <array>

#include "sum_of_two.cpp"

int main()
{
    std::array<value_type, 9> v = {10, 8, 6, 4, 3, 5, 7, 9, 7};
    std::array<value_type, 9> v2 = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    std::array<value_type, 9> v3 = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout << "Testing sum_of_two algorithm...\n\n";

    //=== Test #1
    auto result = sum_of_two(begin(v), end(v), begin(v2), end(v2));

    if (result.second == end(v2))
    {
        std::cout << "No sum in the array A found in the array B\n\n";
    }
    else
    {
        std::cout << "Sum in the array A at index " << result.first.first - begin(v) << " and " << result.first.second - begin(v) << " found in the array B at index " << result.second - begin(v2) << std::endl << std::endl;
    }

    //=== Test #2
    auto result2 = sum_of_two(begin(v), end(v), begin(v3), end(v3));

    if (result2.second == end(v3))
    {
        std::cout << "No sum in the array A found in the array B\n\n";
    }
    else
    {
        std::cout << "Sum in the array A at index " << result2.first.first - begin(v) << " and " << result2.first.second - begin(v) << " found in the array B at index " << result2.second - begin(v3) << std::endl << std::endl;
    }

    //=== Test #3
    auto result3 = sum_of_two(begin(v2), end(v2), begin(v3), end(v3));

    if (result3.second == end(v3))
    {
        std::cout << "No sum in the array A found in the array B\n\n";
    }
    else
    {
        std::cout << "Sum in the array A at index " << result3.first.first - begin(v2) << " and " << result3.first.second - begin(v2) << " found in the array B at index " << result3.second - begin(v3) << std::endl << std::endl;
    }
}
