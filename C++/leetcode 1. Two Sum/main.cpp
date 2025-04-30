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

int main()
{
    int target = 9;
    vector<int> nums = {2, 7, 11, 15};
    vector<int> result = twoSum(nums, target);

    return 0;
}
