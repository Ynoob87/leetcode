#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> map;

        for (int num : nums)
        {
            if (num < 0 || num > nums.size() - 1)
                return -1;
            map[num]++;
        }

        for (int num : nums)
        {
            if (map[num] > 1)
                return num;
        }

        return -1;
    }
};