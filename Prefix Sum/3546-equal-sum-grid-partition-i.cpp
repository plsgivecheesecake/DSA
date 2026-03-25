class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<long long> rowSum(m, 0), colSum(n, 0);

        // Populate rowSum
        for (int i = 0; i < m; i++) {
            long long rSum = 0;
            for (int j = 0; j < n; j++) {
                rSum += grid[i][j];
            }
            rowSum[i] = rSum;
            if (i > 0) rowSum[i] += rowSum[i - 1];
        }
        // Populate colSum
        for (int j = 0; j < n; j++) {
            long long cSum = 0;
            for (int i = 0; i < m; i++) {
                cSum += grid[i][j];
            }
            colSum[j] = cSum;
            if (j > 0) colSum[j] += colSum[j - 1];
        }
        // Check each partition of rowSum
        for (int i = 0; i < m - 1; i++) {
            if (rowSum[i] == (rowSum[m - 1] - rowSum[i])) return true;
        }
        // Check each partition of colSum
        for (int i = 0; i < n - 1; i++) {
            if (colSum[i] == (colSum[n - 1] - colSum[i])) return true;
        }
        return false;
    }
};