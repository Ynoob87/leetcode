class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """

        seen = {}
        for num in nums:
            if num in seen:
                return True
            seen[num] = True
        
        return False
        

print(Solution().containsDuplicate([1,2,3,1]))