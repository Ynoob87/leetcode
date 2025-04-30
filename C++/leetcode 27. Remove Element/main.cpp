#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int> &nums, int val)
{
    int index = 0; // 用來標記有效區域的位置

    // 遍歷陣列
    for (int num : nums)
    {
        if (num != val)
        {                      // 當前數字不等於 val
            nums[index] = num; // 將該數字放入有效區域
            index++;           // 更新有效區域的結束位置
        }
    }

    return index; // 回傳有效區域的長度
}