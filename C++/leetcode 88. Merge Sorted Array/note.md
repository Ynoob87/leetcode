第一次解的時候 出現 heap-buffer-overflow

````cpp
class Solution {
public:
    vector<int> merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> result;

        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] && nums1[i] != 0) {
                result.push_back(nums1[i]);
            }
            if (nums2[i] && nums2[i] != 0) {
                result.push_back(nums1[i]);
            }
        }

        sort(result.begin(), result.end());

        return result;
    }
};```
````

後來注意到題目的 M 和 N 可以當迴圈判斷條件
我這邊有兩個想法
一個是先比較大小 這樣就能直接用最大的那個 當作條件
例如 i < m 然後在加一些條件 來防止溢位

後來是用兩個迴圈 分別 `push_back()` 到一個 Result Vector 我原本以為題目是要 Return Vector
結果吼來發現其實是要 直接修改 num1
所以這邊有兩個寫法 一個是直接 `num1 = result;` 一個是

````cpp
  for (int i = 0; i < m + n; ++i)
            nums1[i] = result[i];```
````

這是最終的解法

````cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> result;

        for (int i = 0; i < m; ++i)
            result.push_back(nums1[i]);
        for (int i = 0; i < n; ++i)
            result.push_back(nums2[i]);

        sort(result.begin(), result.end());

        for (int i = 0; i < m + n; ++i)
            nums1[i] = result[i];
    }
};```
````

![alt text](image.png)

以下是我在此期間問了 AI 什麼問題 希望能夠越刷越不依賴 AI

https://chatgpt.com/share/68188861-ca54-8005-86f6-3a5f365504c4
