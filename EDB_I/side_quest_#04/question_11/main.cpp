#include <iostream>

#include "longest_row_of_zeros.cpp"

int main(){
    value_type **m1 = new int *[4];
    value_type **m2 = new int *[4];
    value_type **m3 = new int *[4];
    value_type base1[4][4] = {{1, 1, 1, 1}, {1, 0, 0, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}};
    value_type base2[4][4] = {{1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}};
    value_type base3[4][4] = {{1, 1, 1, 0}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}};

    for (int i = 0; i < 4; ++i)
    {
        m1[i] = new int[4];
        m2[i] = new int[4];
        m3[i] = new int[4];
    }

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            m1[i][j] = base1[i][j];
            m2[i][j] = base2[i][j];
            m3[i][j] = base3[i][j];
        }
    }

    std::cout << "Testing longest_row_of_zeros algorithm...\n\n";

    //=== Test #1
    auto result = longest_row_of_zeros(m1, 4, 4);

    if (result.first == -1)
    {
        std::cout << "No longest row of zeros found\n\n";
    }
    else
    {
        std::cout << "Longest row of zeros found at index " << result.first << " with value " << result.second << std::endl << std::endl;
    }

    //=== Test #2
    auto result2 = longest_row_of_zeros(m2, 4, 4);

    if (result2.first == -1)
    {
        std::cout << "No longest row of zeros found\n\n";
    }
    else
    {
        std::cout << "Longest row of zeros found at index " << result2.first << " with value " << result2.second << std::endl << std::endl;
    }

    //=== Test #3
    auto result3 = longest_row_of_zeros(m3, 4, 4);

    if (result3.first == -1)
    {
        std::cout << "No longest row of zeros found\n\n";
    }
    else
    {
        std::cout << "Longest row of zeros found at index " << result3.first << " with value " << result3.second << std::endl << std::endl;
    }

    return 0;
}