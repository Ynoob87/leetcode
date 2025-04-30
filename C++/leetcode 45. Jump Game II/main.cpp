#include <iostream>
#include <vector>

using namespace std;

int jump(vector<int> &nums)
{
    if (nums.size() <= 1)
        return 0;

    int jumps = 0;
    int currentEnd = 0;
    int farthest = 0;

    for (int i = 0; i < nums.size() - 1; i++)
    {
        farthest = max(farthest, i + nums[i]);

        // 到了目前這次跳躍的最遠點，就要準備下一次跳
        if (i == currentEnd)
        {
            jumps++;
            currentEnd = farthest;

            // 如果下一次可以跳超過終點，就不用再管後面啦
            if (currentEnd >= nums.size() - 1)
                break;
        }
    }

    return jumps;
}