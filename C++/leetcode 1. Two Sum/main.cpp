#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> hashMap;

    for (int i = 0; i < nums.size(); ++i)
    {
        int complement = target - nums[i];

        if (hashMap.count(complement))
            return {hashMap[complement], i};
        else
            hashMap[nums[i]] = i;
    }

    return {};
}