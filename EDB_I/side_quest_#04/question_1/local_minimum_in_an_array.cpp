#include <iostream>

using value_type = int;

value_type *local_minimum_in_an_array(value_type *begin, value_type *end)
{
    value_type *aux = end;

    while (begin != aux)
    {
        value_type *mid = begin + (aux - begin) / 2;

        if (mid != begin && *mid >= *(mid - 1))
        {
            aux = mid - 1;
        }
        else if (mid != aux - 1 && *mid >= *(mid + 1))
        {
            begin = mid + 1;
        }
        else
        {
            return mid;
        }
    }

    return end;
}
