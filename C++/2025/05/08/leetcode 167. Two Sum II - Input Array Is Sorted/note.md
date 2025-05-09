## 📘 LeetCode 167. Two Sum II - Input Array Is Sorted

### 🧠 題目理解

剛看到題目的時候我有點迷糊，還在想這不就是 Two Sum 嗎？
但我注意到一個關鍵字：「陣列是 1-indexed」，這點讓我興奮地去驗證是不是我想的那樣，結果發現我猜對了～嘿嘿 (⁎˃ᴗ˂⁎)

題目是給一個**遞增排序過的陣列**，然後要求找出兩個 index，使得他們對應的值相加等於 target。
因為已經排序好，所以可以考慮用「雙指標 Two Pointers」或「二分搜尋 Binary Search」！

---

### 🪜 解題過程

一開始我就想用雙指標，但我寫出了這段有點「歪」的 code：

```cpp
vector<int> twoSum(vector<int> &numbers, int target)
{
    int i = 0;
    int j = 0;

    while (i <= j)
    {
        if (numbers[i] == target - numbers[j])
        {
            // TODO: 放答案
        }
        i++;
        j++;
    }

    return numbers;
}
```

🌀 **為什麼這段不對？**

- `i` 和 `j` 一開始都從 0 開始，而且是一起動，等於沒在「夾」中間找答案，會錯過所有可能組合。
- 這時候我知道要用 Two Pointers，但還沒完全理解「雙指標從兩端夾進來」的經典策略。
- 所以我跑去問 AI 證明自己的思路有偏差，然後學到了正確的模板～ ✍️

---

### ✅ 最後 AC 的解法

```cpp
vector<int> twoSum(vector<int> &numbers, int target)
{
    int left = 0, right = numbers.size() - 1;

    while (left <= right)
    {
        int sum = numbers[left] + numbers[right];

        if (target == sum)
            return {left + 1, right + 1};
        else if (sum < target)
            left++;
        else
            right--;
    }

    return {};
}
```

💡 重點：

- 這題已經**排序好**了，所以雙指標是最適解。
- 為了配合題目要求，回傳的 index 是「1-based」的，所以要 `+1`。

---

### 🤯 小插曲：我還拿了以前的 HashMap 解 Two Sum 來玩一下

```cpp
vector<int> twoSum(vector<int>& numbers, int target) {
    unordered_map<int, int> hashMap;

    for (int i = 0; i < numbers.size(); ++i) {
        int complement = target - numbers[i];

        if (hashMap.find(complement) != hashMap.end())
            return {hashMap[complement] + 1, i + 1};
        else
            hashMap[numbers[i]] = i;
    }

    return {};
}
```

雖然這能過，但這題根本不需要用 HashMap 啊 🤣
這也讓我反思一件事：「別再用記憶中的老解法解新題」！
要仔細觀察題目的結構，選擇最適合的策略！

---

### 📌 學到的事

- 「雙指標 Two Pointers」可以很靈活，但也要小心起始條件與移動方式。
- 看懂題目排序特性超重要，有排序 ➝ 通常雙指標 or 二分法優先。
- 有時候不是我不會，而是我**太快把老招拿出來**，導致沒想到更適合的解法。
- 學會了對照測資觀察規則，這比一開始就寫 code 更重要！

---

### 💪 給未來的我

> 嘿～未來的我，記得這題對你來說是「第一個真正理解雙指標策略」的里程碑喔！
>
> 下次再遇到 sorted array 的類型題，就勇敢試試 Two Pointers 吧！
> 也挑戰自己不用 AI 直接解出來，加油，你一定做得到的！٩(๑❛ᴗ❛๑)۶

---
