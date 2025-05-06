## 🧠 LeetCode `Add Two Numbers` 題目學習筆記

### 🔰 題目核心

將兩個反轉順序儲存的非負整數（以 linked list 表示）相加，回傳相同格式的結果 linked list。
舉例：

```
l1 = [2,4,3], l2 = [5,6,4]
代表的數字是 342 + 465 = 807
輸出應為 [7,0,8]
```

---

## 🚶‍♀️ 初始思路

你一開始看到圖片時的理解是：

```
  2 4 3
+ 5 6 4
-------
```

覺得只要同位置相加即可。但當時沒想到「**進位（carry）**」的問題，加上對 linked list 還不熟，就寫出了這樣的版本：

```cpp
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    vector<int> result = {};
    vector<int> nums1 = listToVector(l1);
    vector<int> nums2 = listToVector(l2);

    int maxSize = max(nums1.size(), nums2.size());

    for (int i = 0; i < maxSize; i++)
        result.push_back(nums1[i] + nums2[i]);

    return vectorToList(result);
}
```

---

## 🐛 發現問題

很快就發現幾個 Bug：

1. 長度不同時會 out of range。
2. 沒有處理進位（carry）。
3. 不符合題目的「模擬加法」邏輯。

---

## 💡 解法進化：補 0 + 處理進位

在請教 AI 之後，學到了兩個觀念：

### 🧩 1. 判斷越界：

```cpp
int val1 = (i < nums1.size()) ? nums1[i] : 0;
int val2 = (i < nums2.size()) ? nums2[i] : 0;
```

這行簡潔地補了長度不一致時的 0，超級實用又聰明 ✨！

### 🧮 2. 處理進位：

```cpp
int sum = val1 + val2 + carry;
carry = sum / 10;
result.push_back(sum % 10);
```

- `sum % 10`：只保留個位數。
- `sum / 10`：取得進位（例如 18 → 1）。

---

## ✅ 最終版本解法（vector 模擬加法）

```cpp
ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) {
    vector<int> result = {};
    vector<int> nums1 = listToVector(l1);
    vector<int> nums2 = listToVector(l2);

    int maxSize = max(nums1.size(), nums2.size());
    int carry = 0;

    for (int i = 0; i < maxSize || carry; i++) {
        int val1 = (i < nums1.size()) ? nums1[i] : 0;
        int val2 = (i < nums2.size()) ? nums2[i] : 0;

        int sum = val1 + val2 + carry;
        carry = sum / 10;

        result.push_back(sum % 10);
    }

    return vectorToList(result);
}
```

---

## 🔁 轉換工具

- `listToVector(ListNode*)`：把 linked list 轉成 `vector<int>`，方便操作。
- `vectorToList(vector<int>)`：再把結果轉回 linked list。

---

## 💬 心得小語

你一開始遇到困難，但願意釐清問題、逐步簡化邏輯，這是很棒的學習過程！🎉
理解 carry 與 linked list 的難點，是解這題的關鍵，你已經掌握住啦 (๑>◡<๑)
