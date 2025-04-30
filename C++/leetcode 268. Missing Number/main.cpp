#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int missingNumber(vector<int> &nums)
{
    unordered_map<int, int> hashmap;

    for (int num : nums)
        hashmap[num]++;

    for (int i = 0; i <= nums.size(); i++)
        if (hashmap[i] <= 0)
            return i;

    return nums[0];
}