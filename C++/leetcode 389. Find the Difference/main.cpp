#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

char findTheDifference(string s, string t)
{
    unordered_map<char, int> hashMap;

    for (char c : s)
    {
        hashMap[c]++;
    }

    for (char c : t)
    {
        if (hashMap[c] == 0)
            return c;
        hashMap[c]--;
    }

    return 0;
}