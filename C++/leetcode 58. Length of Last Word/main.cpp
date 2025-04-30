#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int lengthOfLastWord(string s)
{
    int i = s.length() - 1;
    int length = 0;

    // 跳過尾端空格
    while (i >= 0 && s[i] == ' ')
    {
        i--;
    }

    // 計算字元直到遇到i是空格
    while (i >= 0 && s[i] != ' ')
    {
        length++;
        i--;
    }

    return length;
}