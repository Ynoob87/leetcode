#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        string result;
        int maxSize = max(word1.size(), word2.size());
        for (int i = 0; i < maxSize; i++)
        {
            if (i < word1.size())
                result.push_back(word1[i]);
            if (i < word2.size())
                result.push_back(word2[i]);
        }

        return result;
    }
};