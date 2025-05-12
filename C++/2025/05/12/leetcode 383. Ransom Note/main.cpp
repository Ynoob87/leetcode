#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> magazineMap;

        for (char c : magazine)
            magazineMap[c]++; // 統計 magazine 提供的字母數量

        for (char c : ransomNote)
        {
            if (magazineMap[c] == 0)
                return false; // 該字母沒了 or 不夠用
            magazineMap[c]--;
        }

        return true;
    }
};