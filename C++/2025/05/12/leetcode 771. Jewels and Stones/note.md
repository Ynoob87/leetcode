🧠 **LeetCode 771. Jewels and Stones 解題筆記**

---

✨ **題目目標：**

給你兩個字串：

- `jewels`：表示哪些字母是「珠寶」（可能包含大小寫）
- `stones`：表示你擁有的所有「石頭」

請你統計：你擁有的石頭中，有幾個是珠寶 💎
**注意：大小寫視為不同的珠寶！**

---

📌 **解題思路：**

這題屬於「字元查找」＋「頻率統計」的簡單應用。

1. **先把所有珠寶記起來**（用 `unordered_map<char, int>` 存下每個珠寶字元）
2. **接著掃過所有石頭**：

   - 如果這顆石頭是我們的珠寶，就加總到 `count`

3. 因為珠寶字元都可能重複（例如 `jewels = "aAa"`），我們讓 `map` 的 value 記錄次數
4. 如果你不在乎珠寶重複出現的問題，也可以直接用 `unordered_set<char>` 判斷存在與否，效率會再好一點點

---

✅ \*\*AC 寫法：

class Solution
{
public:
int numJewelsInStones(string jewels, string stones)
{
unordered_map\<char, int> store;
int count = 0;

```
    for (char j : jewels)
        store[j]++;

    for (char s : stones)
        if (store[s] > 0)
            count += store[s];

    return count;
}
```

};

---

🌈 **我的學習心得：**

- 這題我一看到就知道可以怎麼解，超有成就感！
- 馬上想到用 `unordered_map` 來記錄珠寶種類，再一個一個檢查石頭中哪些是珠寶
- 雖然題目有大小寫區分，但 map 本身就是區分大小寫的，所以實作起來完全沒煩惱
- 這題讓我更有信心，證明了自己在 **hash table（雜湊）應用上有進步！**
- 希望我可以繼續保持這種 momentum，掌握更多工具與思維模式，未來遇到什麼難題都不怕 (ง •̀\_•́)ง！

---

💬 想補充的延伸思考：

- 如果珠寶清單不重複，其實可以改用 `unordered_set<char>`，因為只需要判斷存不存在
- 更進階的話，這題可以當成：**資料查找效率比較實驗題**

  - `map` vs `unordered_map` vs `set` vs `unordered_set`
  - 不同資料結構的時間複雜度分析

---
