from collections import deque
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        fresh_count = 0 # Keep track of fresh oranges with a counter
        q = deque()
        visited = set()
        m, n = len(grid), len(grid[0])
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    fresh_count += 1 # Update fresh oranges count
                elif grid[i][j] == 2:
                    q.append((i, j)) # Rotten orange found
                    visited.add((i, j)) # BFS policy, add to visited when enqueueing
        timer = 0
        while q and fresh_count > 0:
            for i in range(len(q)): # Traverse all nodes in a level
                oi, oj = q.popleft()
                neighbors = [(oi + 1, oj), (oi - 1, oj), (oi, oj + 1), (oi, oj - 1)]
                for ni, nj in neighbors:
                    if (ni >= 0 and ni < m and nj >=0 and nj < n) and (ni, nj) not in visited and grid[ni][nj] == 1:
                        fresh_count -= 1
                        visited.add((ni, nj))
                        q.append((ni, nj))
            timer += 1

        return timer if fresh_count == 0 else -1