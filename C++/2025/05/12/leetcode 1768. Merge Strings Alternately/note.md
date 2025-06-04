## 🧠 LeetCode 1768. Merge Strings Alternately 解題筆記

### ✨ 題目目標：

將兩個字串交替合併成一個新字串。若兩個字串長度不同，則將剩餘部分直接追加在合併後的字串中。

### 📌 解題思路：

1. **交替合併字串**：從兩個字串的開頭開始交替將字元加入結果字串。
2. **處理不同長度的情況**：若其中一個字串已經用完，繼續將另一個字串剩餘的部分加入結果字串。
3. **時間與空間複雜度**：該解法的時間複雜度是 O(n)，其中 n 是兩個字串中較長的字串長度，空間複雜度是 O(n)。

---

### ✅ 我的 AC 寫法： (輪流 push 字元)

```cpp
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        string result;
        int maxSize = max(word1.size(), word2.size());  // 確定兩個字串中較長的一個
        for (int i = 0; i < maxSize; i++)
        {
            if (i < word1.size())  // 如果 word1 還有字元
                result.push_back(word1[i]);
            if (i < word2.size())  // 如果 word2 還有字元
                result.push_back(word2[i]);
        }

        return result;
    }
};
```

---

### 💡 解法說明：

- 透過 `max(word1.size(), word2.size())` 來確保我們知道兩個字串中較長的一個長度。
- 進入 `for` 迴圈後，依序將兩個字串的字元交替加入到結果字串中，直到一個字串結束。
- 在每次迭代中，會檢查該字串是否還有剩餘字元。如果有則加入，否則跳過。
- 當其中一個字串用完，直接把另一個字串剩餘的部分加入結果。

---

### 🌈 自己的學習歷程紀錄：

- 起初我想過使用**奇數偶數法**來處理，這種方法會在每次處理字串時考慮字元的奇偶性來決定要放哪個字串。
- 後來發現其實可以直接**輪流 push 字元**，這樣簡單而且能夠處理長度不同的情況。
- 經過測試後發現這個解法非常直觀，簡單有效，不需要額外的處理。

---

### 🔥 額外補充（延伸題）：

| 題目                                                                       | 類型           | 難度   | 特點                           |
| -------------------------------------------------------------------------- | -------------- | ------ | ------------------------------ |
| [LeetCode 5](https://leetcode.com/problems/longest-palindromic-substring/) | 最長回文子串   | Medium | 字串相關，動態規劃或中心擴展法 |
| [LeetCode 392](https://leetcode.com/problems/is-subsequence/)              | 子序列檢查     | Easy   | 判斷字串是否為另一字串的子序列 |
| [LeetCode 67](https://leetcode.com/problems/add-binary/)                   | 二進位字串相加 | Easy   | 字串操作、進位計算             |

---
