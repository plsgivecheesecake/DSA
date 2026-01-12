from collections import deque
class Solution:
    def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
        m, n = len(maze), len(maze[0])
        ei, ej = entrance
        q = deque([(ei, ej, 0)])
        visited = set([(ei, ej)])
        nearest = float('inf')
        while q:
            i, j, dist = q.popleft()
            # If the position is on the periphery of the maze, check the distance
            if (i == 0 or i == m - 1 or j == 0 or j == n - 1) and not (i == ei and j == ej):
                nearest = min(nearest, dist)
            neighbors = [(i + 1, j), (i - 1, j), (i, j + 1), (i, j - 1)]
            for ni, nj in neighbors:
                if (ni >= 0 and ni < m and nj >= 0 and nj < n) and (ni, nj) not in visited and maze[ni][nj] != '+':
                    visited.add((ni, nj))
                    q.append((ni, nj, dist + 1))
        return nearest if nearest != float('inf') else -1
            
