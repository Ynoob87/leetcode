#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int longestConsecutive(vector<int> &nums)
{
    int count = 0;
    unordered_map<int, int> hashmap;

    for (int num : nums)
    {
        hashmap[num]++;

        for (int i = 0; i < nums.size(); i++)
        {
            if (hashmap[i] >= 1)
            {
                count++;

                return count;
            }
        }
    }
}