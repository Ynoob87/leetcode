### 📌 題目：**Find the Duplicate Number**（找出重複的數字）

> ✅ 輸入：一個整數陣列 `nums`，只包含 `n+1` 個整數，數值範圍在 `[1, n]`
> ❗ 必有一個數字重複一次以上
> 🧠 回傳**任一個**重複的數字即可

---

### 🌟 我的解題過程（AcWing ➜ LeetCode）

#### 🔹 起點：IG 群聊中的分享

- 有朋友提到 AcWing 題目、但輸入格式看不懂 🥲
- 比起 ZeroJudge，AcWing 比較難上手，格式看起來像 LeetCode，但還需要習慣

#### 🔹 初步思路超直覺！

> 「我最愛 Hash！」✨✨✨
> 這題一看就知道用 `unordered_map` 記錄每個數字出現次數就對了！

---

### ✅ 成功 AC 的版本

```cpp
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> map;

        for (int num : nums)
        {
            // ❗ 防呆：確認數值範圍（非必要，但養成好習慣）
            if (num < 0 || num > nums.size() - 1)
                return -1;
            map[num]++;
        }

        for (int num : nums)
        {
            if (map[num] > 1)
                return num;
        }

        return -1;
    }
};
```

---

### 🧠 中途學到的小知識點

1. **Hash Map vs Set 的差別**

   - `unordered_map<int, int>`：可以儲存 _數字 ➜ 出現次數_
   - `unordered_set<int>`：只能記錄「有沒有出現過」，不能計數唷！

2. **效能小觀察**

   - 相較於排序或 list scan，用 `hash` 計數 **更快也更直觀**！
   - 雖然有點「小題大作」，但這就是「trade-off 交換空間換時間」的好例子！

3. **AcWing 題目格式解析**

   - 函式定義是 LeetCode 風格，不用 `main()`，只要寫出功能即可
   - 提交系統會自動做單元測試 ✨

---

### 🧭 給未來的我

> 當你下一次看到類似「找重複、找出現次數」的題目，不要忘了你有：
>
> - `unordered_map`（記錄頻率）
> - `unordered_set`（判斷是否已出現）
> - **雙迴圈雖可行，但效率差**，善用空間可以換取時間！
> - 快慢指標（Floyd’s Tortoise and Hare）
> - 不使用額外空間（O(1) 空間）

---
