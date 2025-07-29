#include <iostream>
#include <array>

#include "find_a_duplicate.cpp"

int main()
{
    std::array<value_type, 9> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::array<value_type, 9> v2 = {8, 2, 2, 6, 5, 4, 7, 1, 9};

    std::cout << "\nTesting find_a_duplicate algorithm...\n\n";

    //=== Test #1
    auto aux = begin(v);
    std::cout << "Array = [ ";

    while (aux != end(v)-1){
        std::cout << *aux << ", ";
        aux++;
    }
    std::cout << *aux << "]\n";

    auto result = find_a_duplicate(begin(v), end(v));

   
    if (result)
    {
        std::cout << "There are duplicates in the array.\n\n";
    }
    else
    {
        std::cout << "There are no duplicates in the array.\n\n";
    }

    //=== Test #2
    auto aux2 = begin(v2);
    std::cout << "Array = [ ";

    while (aux2 != end(v2) - 1)
    {
        std::cout << *aux2 << ", ";
        aux2++;
    }
    std::cout << *aux2 << "]\n";

    auto result2 = find_a_duplicate(begin(v2), end(v2));

    if (result2)
    {
        std::cout << "There are duplicates in the array.\n ";
    }
    else
    {
        std::cout << "There are no duplicates in the array.\n";
    }
}