#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    vector<int> result;
    int totalProduct = 1;

    for (int num : nums)
    {
        totalProduct *= num;
    }

    for (int num : nums)
    {
        result.push_back(totalProduct / num);
    }

    return result;
}