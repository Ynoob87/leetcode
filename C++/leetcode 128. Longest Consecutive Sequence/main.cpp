#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int longestConsecutive(vector<int> &nums)
{
    if (nums.size() == 0)
    {
        return 0;
    }

    int maxCount = 1;
    int count = 1;

    sort(nums.begin(), nums.end());

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == nums[i - 1])
        {
            continue;
        }
        else if (nums[i] == nums[i - 1] + 1)
        {
            count++;
        }
        else
        {
            count = 1;
        }
        maxCount = max(count, maxCount);
    }

    return maxCount;
}