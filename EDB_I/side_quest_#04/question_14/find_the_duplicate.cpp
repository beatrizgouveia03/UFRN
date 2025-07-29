#include <iostream>
#include <algorithm>

using value_type = int;

std::pair<value_type *, value_type *> find_the_duplicate(value_type *begin, value_type *end)
{
    value_type *aux = begin;

    while (aux != end - 1)
    {
        value_type *low = std::lower_bound(begin, end, *aux);
        value_type *upper = std::upper_bound(begin, end, *aux);

        if (low != upper - 1 && (upper != end || *(upper - 1) == *aux))
        {
            return std::make_pair(low, low + 1);
        }

        aux++;
    }

    return std::make_pair(end, end);
}