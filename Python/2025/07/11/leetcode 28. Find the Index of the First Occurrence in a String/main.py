class Solution(object):
    def strStr(self, haystack, needle):
        if not needle:
            return 0
        
        m = len(haystack)
        n = len(needle)
        
        i = 0
        while i <= m - n:
            j = 0
            while j < n and haystack[i + j] == needle[j]:
                j += 1
            if j == n:
                return i
            i += 1
        
        return -1


print(Solution().strStr("sadbutsad", "sad"))
print(Solution().strStr("leetcode", "leeto"))