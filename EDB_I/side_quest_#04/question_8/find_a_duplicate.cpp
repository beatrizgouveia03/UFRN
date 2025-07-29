#include <iostream>
#include <algorithm>

using value_type = int;

bool find_a_duplicate(value_type *begin, value_type *end)
{
    int size = end - begin;
    for (int i = 0; i < size; i++)
    {
        int idx = std::abs(*(begin + i)) - 1;
        if (*(begin + idx) < 0)
        {
            return true;
        }
        *(begin + idx) = -*(begin + idx);
    }
    return false;
}