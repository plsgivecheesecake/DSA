class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m * n - 1, mid;

        /*
        [
            [1,3,5,7],
            [10,11,16,20],
            [23,30,34,60]
        ]

        1 3 5 7 10 [11] - {1, 1} 16 20 23 30 34 60 [0 - 11] mid = 5

        {x = mid / n = 1}
        {y = mid % n = 1}
        */
        int x = 0, y = 0;

        while (left < right){

            mid = (left + right) / 2;
            
            x = mid / n;
            y = mid % n;

            if (matrix[x][y] < target){
                left  = mid + 1;
            }
            else {
                right= mid;
            }
        }

        mid = (left + right) / 2;
        x = mid / n;
        y = mid % n;

        if (matrix[x][y] == target){
            return true;
        }

        return false;
        
    }
};