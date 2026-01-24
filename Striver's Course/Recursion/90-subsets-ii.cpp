class Solution {
public:
    void generateSubsets(
        int index, 
        vector<int>& buffer, 
        int lastRejected, 
        vector<int>& nums,
        vector<vector<int>>& result
    ) {
        // Base case 1: index has surpassed candidate array bound
        if (index >= nums.size()) {
            result.push_back(buffer);
            return;
        }

        // Base case 2: candidate at index is the same as what was
        // rejected in the previous level of recursion.
        if (nums[index] == lastRejected) {
            generateSubsets(index + 1, buffer, lastRejected, nums, result);
            return;
        }

        // Recursive cases
        // Add element to buffer and call
        buffer.push_back(nums[index]);
        generateSubsets(index + 1, buffer, lastRejected, nums, result);
        // Remove element from buffer, mark it as rejected and call again
        buffer.pop_back();
        generateSubsets(index + 1, buffer, nums[index], nums, result);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // First, sort nums to avoid duplicate 
        // subsets that start with the same element
        std::sort(nums.begin(), nums.end());
        // Initialize buffer and result vectors
        vector<int> buffer = {};
        vector<vector<int>> result;
        // Call method with last rejected as -50, which is outside the constraints
        generateSubsets(0, buffer, -50, nums, result);
        return result;
    }
};