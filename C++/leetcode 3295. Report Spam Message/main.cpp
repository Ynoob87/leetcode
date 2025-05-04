#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool reportSpam(vector<string> &message, vector<string> &bannedWords)
{
    unordered_map<string, int> map;
    int count = 0;

    for (string str : bannedWords)
        map[str]++;

    for (string str : message)
        if (map[str] >= 1)
            count++;

    if (count >= 2)
        return true;
    else
        return false;
}