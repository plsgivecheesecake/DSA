class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        cost.append(0)
        n = len(cost)
        table = [0] * n
        table[0] = cost[0]
        table[1] = cost[1]

        for i in range(2, n):
            table[i] = cost[i] + min(table[i - 1], table[i - 2])

        return table[-1]