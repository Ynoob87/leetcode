#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int singleNonDuplicate(vector<int> &nums)
{
    unordered_map<int, int> map;

    for (int num : nums)
    {
        map[num]++;
        if (map[num] >= 1)
        {
            return num;
        }
    }

    return 0;
}