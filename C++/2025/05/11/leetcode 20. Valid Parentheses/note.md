# 🧠 LeetCode 20. Valid Parentheses 解題筆記

## ✨ 題目目標：

判斷一個字串中的括號是否**配對正確**，包含：

- `()`
- `[]`
- `{}`

---

## 📌 解題思路：

這題的關鍵在於：

1. 遇到**左括號**就放進 stack（等著找它的配對）
2. 遇到**右括號**時，要檢查 stack 最上層是否是對應的左括號（是的話就彈出）
3. 最後確認兩件事：
   - `stack` 是空的（全部配對成功）
   - `n == 0`（配對成功的字元總共剛好抵掉所有字元，防止像 `")()()"` 的錯誤）

---

## ✅ 我的 AC 寫法：

```cpp
bool isValid(string s)
{
    int n = s.size();          // 用來追蹤總長度（後續 n -= 2）
    stack<char> p;

    if (n <= 1)
        return false;          // 長度小於 2 一定不可能合法

    for (char c : s)
    {
        if (c == '(' || c == '{' || c == '[')
            p.push(c);         // 左括號直接進 stack
        else if (!p.empty() &&
                 ((c == ')' && p.top() == '(') ||
                  (c == ']' && p.top() == '[') ||
                  (c == '}' && p.top() == '{')))
        {
            p.pop();           // 成功配對，彈出 stack
            n -= 2;            // 成功配對一對括號，n - 2
        }
    }

    return p.empty() && n == 0;
}
```

---

## 💡 為什麼要用 `n -= 2`？

單純使用 `stack.empty()` 會錯判像這種情況：

```text
")()()"
```

雖然 stack 最後是空的，但開頭的 `)` 沒有配對，理應是不合法。

所以搭配 `n -= 2`，可以追蹤**配對成功的數量是否正確**，多一層保障。

---

## 🌈 自己的學習歷程紀錄：

- 一開始不知道 stack 該怎麼使用，只覺得它像是杯子可以放東西，但無法理解怎麼實際操作。
- 嘗試用 Two Pointers，但發現不能解決這種對稱性複雜的括號匹配。
- 經朋友提醒：**左括號全部無腦 push，右括號就看能不能配對彈出**。
- 終於理解 stack 的妙用：「配對時會剛好從頂端開始 pop 掉」。
- 多寫幾次後，成功寫出不一樣的做法，而且加了 `n -= 2` 來保險機制，讓結果更準確 💪 (不這樣做就無法 AC)

---

## 🔥 額外補充（延伸題推薦）：

| 題目                                                                                     | 類型                       | 難度   | 特點                                      |
| ---------------------------------------------------------------------------------------- | -------------------------- | ------ | ----------------------------------------- |
| [LeetCode 32](https://leetcode.com/problems/longest-valid-parentheses/)                  | 最長合法括號子字串         | Hard   | 要結合 DP or stack 處理邊界與配對長度     |
| [LeetCode 1249](https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/) | 最少移除括號讓字串合法     | Medium | 左右掃兩次，或用 stack 記錄不合法的 index |
| [LeetCode 301](https://leetcode.com/problems/remove-invalid-parentheses/)                | 移除最少括號得到所有可能解 | Hard   | 結合 BFS or backtracking                  |

---
