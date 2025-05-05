#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{

    vector<int> result(nums.size(), 1);

    int left = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        result[i] *= left;
        cout << "[" << result[i] << "," << nums[i] << "]" << "\n";
    }

    cout << "\n";

    int right = 1;
    for (int i = nums.size() - 1; i > 0; i--)
    {
        result[i] *= right;
        cout << "[" << result[i] << "," << nums[i] << "]" << "\n";
    }

    return result;
}