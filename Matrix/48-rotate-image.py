class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        j = n - 1
        for i in range(n // 2):
            for k in range(j):
                matrix[i][i + k], matrix[i + k][n - i - 1], matrix[n - i - 1][n - i - k - 1], matrix[n - i - k - 1][i] = matrix[n - i - k - 1][i], matrix[i][i + k], matrix[i + k][n - i - 1], matrix[n - i - 1][n - i - k - 1]
            j -= 2