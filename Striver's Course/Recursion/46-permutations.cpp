// Using the swapping approach discussed by Striver in L13
class Solution {
public:
    void swapIndicesToGeneratePermutations(int index, vector<int>& nums, vector<vector<int>>& result) {
        // Base Case: index out of bounds
        if (index >= nums.size()) {
            result.push_back(nums);
        }
        // Recursive case
        for (int i = index; i < nums.size(); i++) {
            // Swap elements at i and index
            int temp = nums[index];
            nums[index] = nums[i];
            nums[i] = temp;
            swapIndicesToGeneratePermutations(index + 1, nums, result);
            // Restore to normal
            temp = nums[index];
            nums[index] = nums[i];
            nums[i] = temp;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        swapIndicesToGeneratePermutations(0, nums, result);
        return result;
    }
};