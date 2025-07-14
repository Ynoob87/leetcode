class Solution(object):
    def twoSum(self, nums, target):
        map = {}
        for i, num in enumerate(nums):
            c = target - num
            if c in map:
                return [map[c], i]
            map[num] = i

print(Solution().twoSum([2,7,11,15], 9))