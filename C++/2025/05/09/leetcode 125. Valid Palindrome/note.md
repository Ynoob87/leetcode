### 🧠 題目：Valid Palindrome（驗證回文）

> 判斷一個字串是否為回文，需忽略非字母數字（punctuation）與大小寫差異。

---

### 📓 我的解題歷程（第二次解）

#### ✅ Step 1：想到前後雙指標（Two Pointers）來檢查是否為回文：

```cpp
int i = 0;
int j = s.size() - 1;

while (i <= j) {
    if (s[i] != s[j])
        return false;
    i++;
    j--;
}
```

#### ❌ Step 2：失敗了，因為忘了處理大小寫與非字母數字！

像這個例子：

```
"A man, a plan, a canal: Panama"
```

會出現：

```
s[i] = 'A'，s[j] = 'a' → 這應該是相等的
```

還有標點符號根本不能比較（例如 `, :` 等）

---

### 💡 啟發：那就「**先處理字串**」再來比較吧！

```cpp
string preString;
for (char c : s)
    if (isalnum(c))
        preString += tolower(c);
```

這樣只留下有效的英文與數字，並都轉為小寫了！

接著再用雙指標檢查就沒問題啦：

```cpp
int i = 0, j = preString.size() - 1;
while (i <= j) {
    if (preString[i] != preString[j])
        return false;
    i++, j--;
}
return true;
```

🥳 成功 AC！

![alt text](image.png)

---

### 🧭 給未來的我：

> 👊 你已經懂得 Two Pointers 是處理字串對稱的利器
> 🧼 處理 input 前的「清理（Preprocessing）」超重要，這是大多題目關鍵所在！

---

### 🌟 進階挑戰（之後有空可以挑戰的目標）：

1. **空間優化**：
   不用額外的 `preString` 字串，而是直接在 `s` 上用雙指標跳過不合法字元！

2. **加強 isalnum 與 tolower 的理解**：
   這兩個內建函式其實非常強大，有些題可以靠這些標準工具秒殺。

---
