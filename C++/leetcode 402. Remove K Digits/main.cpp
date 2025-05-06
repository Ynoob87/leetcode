#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string removeKdigits(string num, int k)
{
    // 用來處理數字
    int n = num.size();

    // 遍歷每一個數字
    for (int i = 0; i < n && k > 0; i++)
    {
        // 當遇到較小的數字時，刪除前一個較大的數字
        while (k > 0 && i > 0 && num[i] < num[i - 1])
        {
            num.erase(i - 1, 1);
            k--;
            i--;
        }
    }

    // 如果還有剩餘的k，則刪除最後的幾個數字
    while (k > 0)
    {
        num.erase(num.size() - 1, 1);
        k--;
    }

    // 移除前導零
    int start = 0;
    while (start < num.size() && num[start] == '0')
    {
        start++;
    }

    string result = num.substr(start);

    // 如果結果是空的，返回"0"
    return result.empty() ? "0" : result;
}
