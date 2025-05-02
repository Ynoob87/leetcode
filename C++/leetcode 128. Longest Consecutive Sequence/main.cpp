#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int longestConsecutive(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;

    int maxCount = 1;
    int count = 1;

    sort(nums.begin(), nums.end());

    for (int i = 1; i < nums.size(); i++)
        if (nums[i] == nums[i - 1])
            continue; // 跳過重複數字
        else if (nums[i] == nums[i - 1] + 1)
            count++;
        else
            count = 1;               // 重置計數器
    maxCount = max(count, maxCount); // 比較當前計數器是否大於歷史紀錄

    return maxCount;
}