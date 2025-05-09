## 📘 LeetCode 36. Valid Sudoku 解題筆記

### 🧠 心魔關卡：從逃避到挑戰

- 小時候超愛玩數獨，所以其實對規則蠻熟的（只是沒想過要用 code 解 XD）
- 但之前一看到這題就直接跳過，因為：

  - 是二維陣列 ➝ 滿滿的字元讓人直接想關頁面 🥲
  - 題目難度是 Medium ➝ 感覺好像會卡很久
  - 還看到留言說：「如果面試問這題，代表他根本不想錄用你」😨

💡 **還好有朋友「老鼠」 (shiba001\_) 的一句話：**

> 「還好吧，不就判斷有沒有重複的？」

讓我有勇氣面對它了！(ง •̀\_•́)ง

---

### 🧩 解法與踩雷日記

#### ✅ 陣列版本（成功 AC！）

```cpp
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rowCount[9][9] = {0};
        int colCount[9][9] = {0};
        int boxCount[9][9] = {0};

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                char val = board[i][j];
                if (val == '.') continue;

                int num = val - '1'; // 將 '1'-'9' 轉成 0~8
                int boxIndex = (i / 3) * 3 + (j / 3); // ➜ 魔法公式 ✨

                if (rowCount[i][num] || colCount[j][num] || boxCount[boxIndex][num])
                    return false;

                rowCount[i][num]++;
                colCount[j][num]++;
                boxCount[boxIndex][num]++;
            }
        }

        return true;
    }
};
```

📌 **學到的重點：**

- **char ➝ int**：`val - '1'`，簡單直觀又實用
- **box index 計算公式**：`(i / 3) * 3 + (j / 3)` 是這題的靈魂
- 陣列比 hash 更省空間、效率也比較好！

---

#### ❓HashMap 嘗試

一開始試圖這樣寫：

```cpp
unordered_map<char, int, int> boxCount[9]; // ❌ 錯了！unordered_map 只能兩個 template 參數
```

才發現……我幹嘛不用陣列 😭

---

#### ✅ HashMap 實作（也是正確的）

```cpp
bool isValidSudoku(vector<vector<char>> &board) {
    unordered_map<char, int> rowCount[9];
    unordered_map<char, int> colCount[9];
    unordered_map<char, int> boxCount[9];

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            char val = board[i][j];
            if (val == '.') continue;

            int boxIndex = (i / 3) * 3 + (j / 3);

            if (rowCount[i][val] > 0 || colCount[j][val] > 0 || boxCount[boxIndex][val] > 0)
                return false;

            rowCount[i][val]++;
            colCount[j][val]++;
            boxCount[boxIndex][val]++;
        }
    }

    return true;
}
```

💬 優點是寫法直覺，不用轉換，但效能比陣列略差一些（因為 hash 還是會有 overhead）

---

#### 😵 寫錯但收穫滿滿的版本

```cpp
unordered_map<char, int> rowCount;
unordered_map<char, int> colCount;
unordered_map<char, int> boxCount;

...

// 錯：沒用 box index ➝ key 被覆蓋了
boxCount[boxIndex] = val;
rowCount[i] = val;
colCount[j] = val;
```

這讓我更理解：**記錄每行/列/宮格時，不能共用同一個 map！**

---

### ✨ 總結我學到的

- ✅ 二維陣列的索引處理方式
- ✅ 如何計算 box index ➝ `(i / 3) * 3 + (j / 3)`
- ✅ `char` ➝ `int` 的轉換技巧
- ✅ 試著換不同資料結構後的取捨思考
- ✅ 錯誤寫法反而更有幫助我理解正確邏輯（重要）
- ✅ 陣列有時比 hash 簡單又高效
- ✅ 最重要的是，不要被網路留言嚇退！

---

### 🧡 給 shiba001\_ 的小感謝

謝謝你一直都在我的身邊，不管是學習還是低潮期都陪著我
我常常丟一堆難題給你，你還是都很耐心回我 (ಥ﹏ಥ)
也謝謝你自己為了目標努力的樣子，讓我有追趕的方向
如果沒遇到你，我可能現在還是只會想，不敢真的做題
雖然我的路有點像困難模式，但我會努力走下去的！

---

### 💪 給未來的我

> 不管一開始多害怕、多不想面對，只要願意踏出第一步，就已經超棒了
> 你撐過了「看不懂題目就直接跳過」的階段
> 現在的你，正在變強！別忘了這份堅持與勇氣 ✨
> Keep going！未來一定會謝謝現在努力的你！
