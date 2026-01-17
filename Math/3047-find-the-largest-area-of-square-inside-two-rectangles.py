class Solution:
    def largestSquareArea(self, bottomLeft: List[List[int]], topRight: List[List[int]]) -> int:
        n = len(bottomLeft)
        # Compute spans
        span = [
            [[bottomLeft[i][0], topRight[i][0]], [bottomLeft[i][1], topRight[i][1]]]
            for i in range(n)
        ]
        result = 0
        # For each pair, compute overlap
        for i in range(n - 1):
            for j in range(i + 1, n):
                # Clip overlap to 0. Reminds me of ReLU
                x_intersection = max(min(span[j][0][1], span[i][0][1]) - max(span[j][0][0], span[i][0][0]), 0)
                y_intersection = max(min(span[j][1][1], span[i][1][1]) - max(span[j][1][0], span[i][1][0]), 0)
                result = max(min(x_intersection, y_intersection) ** 2, result)
        return result
                
                