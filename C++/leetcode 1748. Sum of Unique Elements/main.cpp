#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int sumOfUnique(vector<int> &nums)
{
    unordered_map<int, int> map;
    int total = 0;
    for (int num : nums)
        map[num]++;
    for (int num : nums)
        if (map[num] == 1)
            total += num;
    return total;
}