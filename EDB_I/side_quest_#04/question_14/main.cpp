#include <iostream>
#include <array>

#include "find_the_duplicate.cpp"

int main()
{
    std::array<value_type, 9> v = {10, 8, 6, 4, 3, 5, 7, 9, 7};
    std::array<value_type, 9> v2 = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    std::array<value_type, 9> v3 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::array<value_type, 9> v4 = {8, 2, 2, 6, 5, 4, 7, 1, 9}; 

    std::cout << "Testing find_the_duplicate algorithm...\n\n";

    //=== Test #1
    std::sort(begin(v), end(v));
    auto aux = begin(v);
    std::cout << "Array = [ ";

    while (aux != end(v) - 1)
    {
        std::cout << *aux << ", ";
        aux++;
    }
    std::cout << *aux << "]\n";

    auto result1 = find_the_duplicate(begin(v), end(v));

    if (result1.second == end(v))
    {
        std::cout << "No duplicate found in the array\n\n";
    }
    else
    {
        std::cout << "Duplicate found at index " << result1.first - begin(v) << " and " << result1.second - begin(v) << std::endl << std::endl;
    }

    //=== Test #2
    std::sort(begin(v2), end(v2));
    auto aux2 = begin(v2);
    std::cout << "Array = [ ";

    while (aux2 != end(v2) - 1)
    {
        std::cout << *aux2 << ", ";
        aux2++;
    }
    std::cout << *aux2 << "]\n";

    auto result2 = find_the_duplicate(begin(v2), end(v2));

    if (result2.second == end(v2))
    {
        std::cout << "No duplicate found in the array\n\n";
    }
    else
    {
        std::cout << "Duplicate found at index " << result2.first - begin(v2) << " and " << result2.second - begin(v2) << std::endl << std::endl;
    }

    //=== Test #3
    std::sort(begin(v3), end(v3));
    auto aux3 = begin(v3);
    std::cout << "Array = [ ";

    while (aux3 != end(v3) - 1)
    {
        std::cout << *aux3 << ", ";
        aux3++;
    }
    std::cout << *aux3 << "]\n";

    auto result3 = find_the_duplicate(begin(v3), end(v3));

    if (result3.second == end(v3))
    {
        std::cout << "No duplicate found in the array\n\n";
    }
    else
    {
        std::cout << "Duplicate found at index " << result3.first - begin(v3) << " and " << result3.second - begin(v3) << std::endl << std::endl;
    }

    return 0;
}