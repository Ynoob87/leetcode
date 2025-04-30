#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int, int> hashMap;
    vector<int> result;

    for (int num : nums1)
    {
        hashMap[num]++;
    }

    for (int num : nums2)
    {
        if (hashMap[num] > 0)
        {
            result.push_back(num);
            hashMap[num]--;
        }
    }

    return result;
}