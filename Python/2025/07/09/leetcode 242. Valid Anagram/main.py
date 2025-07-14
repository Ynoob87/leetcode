class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        
        sorted_str1 = sorted(s)
        sorted_str2 = sorted(t)

        return sorted_str1 == sorted_str2


print(Solution().isAnagram("anagram", "nagaram"))