class Solution {
public:
    void constructGrid(vector<vector<int>>& grid, vector<vector<string>>& result) {
        vector<string> candidate;
        for (vector<int> row : grid) {
            string candidateRow = "";
            for (int element : row) {
                if (element == 1) {
                    candidateRow += "Q";
                }
                else {
                    candidateRow += ".";
                }
            }
            candidate.push_back(candidateRow);
        }
        result.push_back(candidate);
    }
    void solver(
        int rowIndex, // Current row index
        int n, // Grid dimension
        vector<vector<int>>& grid, // Grid representation
        vector<int>& columnHash,
        vector<int>& rightDiagonalHash,
        vector<int>& leftDiagonalHash,
        vector<vector<string>>& result
    ) {
        // Base case
        if (rowIndex >= n) {
            constructGrid(grid, result);
            return;
        }
        // Recursive Case
        for (int columnIndex = 0; columnIndex < n; columnIndex++) {
            // Check hash arrays to see whether it's safe to place the queen
            if (
                !columnHash[columnIndex] 
                && !rightDiagonalHash[rowIndex + columnIndex]
                && !leftDiagonalHash[n - 1 + columnIndex - rowIndex] // Remember this formula
            ) {
                columnHash[columnIndex] = 1;
                rightDiagonalHash[rowIndex + columnIndex] = 1;
                leftDiagonalHash[n - 1 + columnIndex - rowIndex] = 1;
                grid[rowIndex][columnIndex] = 1;
                // Call solver recursively
                solver(rowIndex + 1, n, grid, columnHash, rightDiagonalHash, leftDiagonalHash, result);
                // When the control returns from the recursive call, unset everything that was set
                columnHash[columnIndex] = 0;
                rightDiagonalHash[rowIndex + columnIndex] = 0;
                leftDiagonalHash[n - 1 + columnIndex - rowIndex] = 0;
                grid[rowIndex][columnIndex] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<vector<int>> grid(n, vector<int>(n, 0));
        // Let's use hashing instead of iterating over the grid
        vector<int> columnHash(n, 0);
        vector<int> rightDiagonalHash(2 * n - 1, 0); // Formula: row + col
        vector<int> leftDiagonalHash(2 * n - 1, 0); // Formula: (n - 1) + (col - row) 
        solver(0, n, grid, columnHash, rightDiagonalHash, leftDiagonalHash, result);
        return result;
    }
};