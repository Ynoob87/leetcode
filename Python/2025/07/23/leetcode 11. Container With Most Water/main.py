class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int

        O(N)
        """
        
        left = 0
        right = len(height) - 1

        max_area = 0

        while (left < right):
            area = min(height[left], height[right]) * (right - left)
            max_area = max(area, max_area)

            if height[left] < height[right]:
                left += 1
            else:
                right -= 1

        return max_area

print(Solution().maxArea([1,8,6,2,5,4,8,3,7]))
print(Solution().maxArea([1,1]))