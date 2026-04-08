class Solution:
    def __init__(self):
        self.unique_solutions = 0

    def backtrack(self, row_index: int, board_size: int, cols: List[int], left_diags: List[int], right_diags: List[int]) -> None:
        if row_index >= board_size:
            self.unique_solutions += 1
            return

        for col_index in range(board_size):
            if cols[col_index] == 0 and right_diags[row_index + col_index] == 0 and left_diags[col_index - row_index + board_size - 1] == 0:
                cols[col_index] = 1
                right_diags[row_index + col_index] = 1
                left_diags[col_index - row_index + board_size - 1] = 1
                self.backtrack(row_index + 1, board_size, cols, left_diags, right_diags)
                cols[col_index] = 0
                right_diags[row_index + col_index] = 0
                left_diags[col_index - row_index + board_size - 1] = 0
    
    
    def totalNQueens(self, n: int) -> int:
        # Define four flag arrays
        cols = [0 for i in range(n)]
        left_diags = [0 for i in range((2 * n) - 1)]
        right_diags = [0 for i in range((2 * n) - 1)]

        self.backtrack(0, n, cols, left_diags, right_diags)
        return self.unique_solutions    