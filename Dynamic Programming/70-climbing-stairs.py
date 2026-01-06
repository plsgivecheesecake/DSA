class Solution:
    def climbStairs(self, n: int) -> int:
        
        memo = {}

        def dp(i):
            if i <= 1:
                return 1
            if memo.get(i):
                return memo[i]
            memo[i] = dp(i - 1) + dp(i - 2)
            return memo[i]

        return dp(n)