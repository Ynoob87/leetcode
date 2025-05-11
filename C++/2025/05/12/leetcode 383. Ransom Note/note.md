## 🧠 LeetCode 383. Ransom Note 解題筆記

---

### ✨ 題目目標：

給你兩個字串：

- `ransomNote`（勒索信）：你想組出來的目標內容
- `magazine`（雜誌）：你手上可用的字母

請判斷：**是否可以用雜誌提供的字母，組出勒索信？**
⚠️ 每個字母只能用一次！（不能重複使用喔！）

---

### ❌ 錯誤寫法（第一次理解錯題意）：

```cpp
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> ransomNoteMap;
        unordered_map<char, int> magazineMap;

        for (char c : ransomNote)
            ransomNoteMap[c]++;
        for (char c : magazine)
            magazineMap[c]++;
        for (char c : magazine)
            if (ransomNoteMap.count(c) && (ransomNoteMap[c] == magazineMap[c]))
                return true;

        return false;
    }
};
```

#### 🔎 問題點：

- 把題目理解成：「雜誌和勒索信中有沒有一樣的字母＆出現次數是否相同」
- 但實際題意是：「**magazine 的字母能否湊出 ransomNote**」，而且字母只能使用一次！
- 像 `"aa"` 與 `"ab"` 應該回傳 `false`，但這段程式碼卻會錯判為 `true` ❌

---

### ✅ 修正後的正確解法：

```cpp
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> magazineMap;

        for (char c : magazine)
            magazineMap[c]++; // 統計 magazine 提供的字母數量

        for (char c : ransomNote)
        {
            if (magazineMap[c] == 0)
                return false; // 該字母沒了 or 不夠用
            magazineMap[c]--;
        }

        return true;
    }
};
```

---

### 🌈 自己的學習歷程紀錄：

- 一看到題目就覺得：「啊這好像珠寶與石頭的反轉版！」（也用 map）
- 快速寫出錯誤版本，覺得邏輯有通，結果提交直接錯 ❌
- 上網查才發現：**搞錯題目方向了** → 原來是 magazine 要「供應」ransomNote，不是單純比較內容是否一致
- 這次錯誤讓我學到：**理解題目文字超重要！** 有時不是演算法的錯，而是思維方向搞反了。

---

### 🚀 額外優化寫法（用陣列加速）：

```cpp
bool canConstruct(string ransomNote, string magazine)
{
    int count[26] = {0};

    for (char c : magazine)
        count[c - 'a']++;

    for (char c : ransomNote)
        if (--count[c - 'a'] < 0)
            return false;

    return true;
}
```

---

### 💬 心得與反思：

- 看似簡單的題，卻是個思維陷阱！
- 我覺得自己的 hash 技巧越來越純熟了，但還是要提醒自己：
  ✅ **先確認需求，再設計解法！**
- 這次的錯誤，幫我踩了一次坑，下次再也不會搞錯啦 💪
