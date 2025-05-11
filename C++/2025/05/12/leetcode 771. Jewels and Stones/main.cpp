#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int numJewelsInStones(string jewels, string stones)
    {
        unordered_map<char, int> store;
        int count = 0;

        for (char j : jewels)
            store[j]++;

        for (char s : stones)
            if (store[s] > 0)
                count += store[s];

        return count;
    }
};