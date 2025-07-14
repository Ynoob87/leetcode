class Solution(object):
    def removeDuplicates(self, nums, k = 2):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) <= k:
            return len(nums)

        slow = k
        for fast in range(k, len(nums)):
            if nums[fast] != nums[slow - k]:
                nums[slow] = nums[fast]
                slow += 1
        return slow 

print(Solution().removeDuplicates([1,2,3]))