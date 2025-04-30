#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    vector<int> result = {};
    unordered_map<int, int> count_map;

    // 計算相同數字出現的頻率
    for (int num : nums)
    {
        count_map[num]++;
    }

    // 把count_map轉換成vector方便排序
    vector<pair<int, int>> count_vector;
    for (const auto &entry : count_map)
    {
        count_vector.push_back({entry.second, entry.first});
    }

    // 把count_map排序 並反轉頭尾
    sort(count_vector.begin(), count_vector.end());
    reverse(count_vector.begin(), count_vector.end());

    for (int i = 0; i < k; i++)
    {
        cout << count_vector[i].second << "\n";
        result.push_back(count_vector[i].second);
    }

    return result;
}