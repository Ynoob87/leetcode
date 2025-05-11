#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> ransomNoteMap;
        unordered_map<char, int> magazineMap;

        for (char c : ransomNote)
            ransomNoteMap[c]++;
        for (char c : magazine)
            magazineMap[c]++;
        for (char c : magazine)
            if (ransomNoteMap.count(c) && (ransomNoteMap[c] != magazineMap[c]))
                return false;

        return true;
    }
};