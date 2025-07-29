#include <iostream>
#include <algorithm>

using value_type = int;

std::pair<std::pair<value_type *, value_type *>, value_type *> sum_of_two(value_type *beginA, value_type *endA, value_type *beginB, value_type *endB)
{
    value_type *aux = beginA;

    while (aux != endA - 1)
    {
        for (auto it = aux + 1; it != endA; ++it)
        {
            value_type sum = *aux + *it;
            for (auto it2 = beginB; it2 != endB; ++it2)
            {
                if (*it2 == sum)
                {
                    return std::make_pair(std::make_pair(aux, it), it2);
                }
            }
        }

        aux++;
    }

    return std::make_pair(std::make_pair(endA, endA), endB);
}
