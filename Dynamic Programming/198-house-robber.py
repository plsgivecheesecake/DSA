class Solution:
    def rob(self, nums: List[int]) -> int:
        # Let's solve using tabulation this time,
        # and maybe later, I'll try to solve using memoization
        table = [0] * (len(nums) + 1)
        table[1] = nums[0]
        for i in range(1, len(nums)):
            table[i + 1] = max(nums[i] + table[i - 1], table[i])
        return table[-1] 
