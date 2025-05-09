#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> topKFrequent(vector<string> &words, int k)
{
    unordered_map<string, int> map;

    for (string &word : words)
        map[word]++;

    vector<pair<string, int>> vec(map.begin(), map.end());

    sort(vec.begin(), vec.end(), [](const auto &a, const auto &b)
         {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second > b.second; });

    vector<string> result;
    for (int i = 0; i < k; ++i)
        result.push_back(vec[i].first);

    return result;
}