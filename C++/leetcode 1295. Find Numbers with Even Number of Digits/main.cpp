#include <iostream>
#include <vector>

using namespace std;

int findNumbers(vector<int> &nums)
{
    int result = 0;

    for (int num : nums)
        if ((to_string(num).size()) % 2 == 0)
            result++;

    return result;
}