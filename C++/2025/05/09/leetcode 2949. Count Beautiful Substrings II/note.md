## 💡 題目：**Beautiful Substrings**（LeetCode Hard 題）

> 給定一個字串 `s` 和一個整數 `k`，找出所有滿足以下條件的子字串數量：
>
> 1. 子字串中母音數量 == 子音數量
> 2. `母音數量 × 子音數量 % k == 0`

---

## 🔎 初步觀察

### 🔹 字串掃描目標

- 枚舉所有可能子字串（從 `i` 到 `j`）
- 統計其中：

  - 母音（a, e, i, o, u）個數
  - 子音個數

### 🔹 條件

- `vowels == consonants`
- `(vowels * consonants) % k == 0`

---

## 🧠 初版解法（Brute Force 暴力法）

你自己手刻出來的版本如下 👏：

```cpp
long long beautifulSubstrings(string s, int k)
{
    int count = 0;

    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i + 1; j < s.size(); j++)
        {
            int vowels = 0;
            int consonants = 0;

            for (int index = i; index <= j; index++)
            {
                if (s[index] == 'a' || s[index] == 'e' || s[index] == 'i' || s[index] == 'o' || s[index] == 'u')
                    vowels++;
                else
                    consonants++;
            }

            if (vowels != consonants)
                continue;

            if ((vowels * consonants) % k == 0)
                count++;
        }
    }
    return count;
}
```

---

## 🧩 時間複雜度分析

- 外層兩層 `i` 和 `j`：`O(n^2)`
- 內層統計母音/子音：最多 `O(n)`
- 總體時間複雜度：**`O(n^3)`**

⚠️ 這在實戰中（像 LeetCode 測資比較嚴苛）很容易 **TLE（Time Limit Exceeded）**

---

## 🧑‍🏫 群友的進階思路（Prefix Sum + 優化）

你說你朋友瞬間就解出來 ✨ 他真的超強！
他的做法大概是：

### ✅ 預處理 Prefix Sum

- 建立 prefix array 記錄到每個位置為止：

  - 母音累積數
  - 子音累積數

- 比較兩區間的差值，快速取得某段的母音與子音數量

### ✅ 利用 Hash Map 儲存 `(vowel - consonant)` 與出現次數

- 判斷 `vowel == consonant` ➜ 代表 prefix 的差值相同
- 再配合 `(v * c) % k == 0` 去檢查

這會把時間複雜度降到 **O(n^2)** 甚至更低！

---

## 🧠 學習重點整理

| 技術點             | 用法                                            |     |           |     |        |
| ------------------ | ----------------------------------------------- | --- | --------- | --- | ------ |
| Brute Force 暴力法 | 小測資可用，驗證邏輯最快的方式                  |     |           |     |        |
| 母音判斷           | \`if (ch == 'a'                                 |     | ch == 'e' |     | ...)\` |
| Prefix Sum 思路    | 累積統計值讓你 O(1) 得出任意區間統計            |     |           |     |        |
| 優化條件判斷       | `v == c && (v*c)%k==0` 用邏輯切入避免不必要迴圈 |     |           |     |        |
| 計數器 map         | 儲存出現過的狀態以便快速查找                    |     |           |     |        |

---

## 🔚 小總結 & 給未來的自己 🎯

> 🌱 雖然這次是暴力法，但你邏輯很清楚，程式也寫對了！
> 🌸 難題最好的練習方式就是「先寫得出來」→「再學怎麼優化」
> 🚀 你有實戰、有討論、有驗證，這樣才是最扎實的進步啊！

---
