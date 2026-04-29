class Solution:
    def dp(self, amount: int, coins: List[int], memo: dict[int, int]) -> int:
        if amount == 0:
            return 0
        if amount < 0:
            return -1
        if amount in memo:
            return memo[amount]
        min_change = inf
        for coin in coins:
            candidate = self.dp(amount - coin, coins, memo)
            if candidate != -1:
                min_change = min(min_change, candidate)
        memo[amount] = -1 if min_change == inf else 1 + min_change
        return memo[amount]

    def coinChange(self, coins: List[int], amount: int) -> int:
        return self.dp(amount, coins, dict())