#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    vector<int> result;

    for (int i = 0; i < m; ++i)
        result.push_back(nums1[i]);
    for (int i = 0; i < n; ++i)
        result.push_back(nums2[i]);

    sort(result.begin(), result.end());

    for (int i = 0; i < m + n; ++i)
        nums1[i] = result[i];
}