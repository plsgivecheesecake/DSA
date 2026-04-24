class Solution:
    def maxArea(self, height: List[int]) -> int:
        L, R = 0, len(height) - 1
        most_water = 0
        while L < R:
            most_water = max(most_water, min(height[L], height[R]) * (R - L))
            if height[L] <= height[R]:
                L += 1
            else:
                R -= 1
        return most_water
