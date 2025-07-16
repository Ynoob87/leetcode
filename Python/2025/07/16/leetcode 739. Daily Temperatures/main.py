class Solution(object):
    def dailyTemperatures(self, temperatures):
        """
        :type temperatures: List[int]
        :rtype: List[int]
        
        題目要求：
        - 給定一串氣溫列表，對每一天，回傳還要幾天才會遇到「比今天更熱的溫度」
        - 若未來都不會再變熱，就回傳 0
        - 例如：73, 74 → 答案是 1，因為明天就會變熱
        - 輸出是一個與輸入等長的 List[int]
        """

        stack = []  # 這裡其實是 result，我原本用 stack 作為暫存結果的變數名
        for i in range(len(temperatures)):
            found = False  # 我一開始把這個放錯地方，導致結果一直錯

            # 嘗試從明天開始往後找，找出第一個比今天熱的溫度
            for j in range(i + 1, len(temperatures)):

                # 如果找到了，就記下相差天數 j - i
                if temperatures[i] < temperatures[j]:
                    stack.append(j - i)
                    found = True  # 標記有找到
                    break  # 找到就不用再往後比了

            # 如果整個迴圈都沒找到，代表未來不會變熱，就記 0
            if not found:
                stack.append(0)
        return stack
    
print(Solution().dailyTemperatures([73,74,75,71,69,72,76,73]))