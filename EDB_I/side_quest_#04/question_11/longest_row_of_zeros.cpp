#include <iostream>
#include <algorithm>

using value_type = int;

std::pair<value_type, value_type> longest_row_of_zeros(value_type **matrix, int rows, int cols)
{
    int row_with_most_zeros = -1;
    int max_zeros = 0;

    for (int i = 0; i < rows; ++i)
    {
        value_type zeros_in_the_row = std::count(&matrix[i][0], &matrix[i][cols], 0);
        if (zeros_in_the_row > max_zeros)
        {
            max_zeros = zeros_in_the_row;
            row_with_most_zeros = i;
        }
        else if (zeros_in_the_row == max_zeros)
        {
            row_with_most_zeros = -1;
        }
    }

    std::pair<value_type, value_type> result = std::make_pair(row_with_most_zeros, max_zeros);

    return result;
}
