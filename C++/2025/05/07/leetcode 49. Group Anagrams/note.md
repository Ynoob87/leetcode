## 📘 LeetCode 49. Group Anagrams（二刷筆記）

### 🧠 前情提要（解題回憶）

這是我**第二次**做這題！
第一次解的時候，幾乎全程靠 AI 幫我引導，自己還有點懵懂；但這次回來挑戰時，我**馬上就知道關鍵是要用 Hash Table 和排序**✨
還有具體該怎麼實現的步驟
這種感覺超爽的，代表我真的有在進步！

但還是有遇到一些困難 跟粗心

---

### 🧩 解題關鍵與收穫

#### ✅ 我這次的正確做法

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> map;

        for (string s : strs) {
            string sorted = s;
            sort(sorted.begin(), sorted.end());
            map[sorted].push_back(s); // 👍 把原始字串丟進對應的 group
        }

        for (auto group : map) {
            result.push_back(group.second);
        }

        return result;
    }
};
```

📌 學到的觀念：

- **Hash Table 的 key 要用排序過的字串**，這是所有 anagram 共有的特徵
- `unordered_map<string, vector<string>> map;`：這樣才能把一組組 anagram 分組起來
- `auto` 的用法超實用，可以簡化 map 的遍歷
- 最後只需要把 `group.second` 推進 `result` 就完成啦！

---

### 🔄 中間我遇到的一些迷失與修正

當時我一度對 map 的用法搞錯方向，我以為 map 是**自動記錄**，結果寫出像這樣的錯誤代碼：

```cpp
map[sorted] = s; // ❌ 這樣會覆蓋 key 對應的 value，而不是 append！
```

甚至還嘗試了這種怪怪的寫法：

```cpp
for (string s : strs){
    string sorted = s;
    sort(sorted.begin(), sorted.end());
    vector<string> list;

    list.push_back(map[sorted] = s); // ❌ 錯得一塌糊塗 QQ
}
```

還有一個地方是我原本遍歷 map 的時候，犯了直接 `push_back(group)` 的錯誤，忘了取 `.second`。
幸好在過程中 AI 提醒了我幾次這些細節，也讓我慢慢修正過來 💡

---

### ✨ 我的成長與反思

- **這次只有一小段程式邏輯是靠 AI 提醒的**（map\[sorted].push_back(s)），大部分都靠我自己完成！
- 我更理解了 unordered_map 的運作邏輯，知道它不是「自動 append」，而是要自己指定好資料結構。
- 相比第一次那種懵懵懂懂的狀態，現在的我能夠**獨立思考錯在哪、怎麼修正、背後的邏輯是什麼**
- 覺得自己越來越能掌握「分組」這類經典 hash 題的解法，也更有信心面對類似題目了 (⁎˃ᴗ˂⁎)

---

### 💪 給未來的我

> 每一次回頭重新做題，不只是複習，也是見證成長的過程！
> 你現在能寫出乾淨漂亮的解法，錯過的地方也願意學習修正，這就是工程師最重要的心態呀 ✨
> Keep going ～我們繼續刷題，一起變強吧！(๑•̀ㅂ•́)و✧

---
