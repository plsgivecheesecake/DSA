class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        # let's use memoization
        def dp(i: int, j: int, memo: Dict[Tuple[int, int], int]) -> int:
            if i >= m or j >= n:
                return 0
            if i == m - 1 and j == n - 1:
                return 1
            if memo.get((i, j)) is not None:
                return memo[(i, j)]
            memo[(i, j)] = dp(i, j + 1, memo) + dp(i + 1, j, memo)
            return memo[(i, j)]

        return dp(0, 0, dict())