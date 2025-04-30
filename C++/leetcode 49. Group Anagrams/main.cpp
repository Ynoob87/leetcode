#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> groups;
    vector<vector<string>> result;

    for (string str : strs)
    {
        string sortedStr = str;
        sort(sortedStr.begin(), sortedStr.end());
        groups[sortedStr].push_back(str);
    }

    for (auto group : groups)
    {
        result.push_back(group.second);
    }

    return result;
}