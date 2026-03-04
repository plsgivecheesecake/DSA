#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Method to find the closest subsequence sum to the goal
    int minAbsDifference(vector<int>& nums, int goal) {
        // Divide the array into two halves
        int n = nums.size();
        vector<int> left(nums.begin(), nums.begin() + n / 2);
        vector<int> right(nums.begin() + n / 2, nums.end());

        // Generate all possible sums for both halves
        vector<int> leftSums = generateSubsequenceSums(left);
        vector<int> rightSums = generateSubsequenceSums(right);

        // Sort the right half sums for binary search
        sort(rightSums.begin(), rightSums.end());

        int minDiff = INT_MAX;

        // Compare each sum from the left half with the closest sum from the right half
        for (int sum : leftSums) {
            int target = goal - sum;
            minDiff = min(minDiff, abs(target)); // Compare with 0 (empty subsequence)

            auto it = lower_bound(rightSums.begin(), rightSums.end(), target);
            if (it != rightSums.end() && *it == target) {
                return 0; // If exact match is found
            }

            // If no exact match, find the closest values
            if (it != rightSums.end()) {
                minDiff = min(minDiff, abs(target - *it));
            }
            if (it != rightSums.begin()) {
                minDiff = min(minDiff, abs(target - *(prev(it))));
            }
        }

        return minDiff;
    }

    // Method to generate all possible sums of subsequences for a given array
    vector<int> generateSubsequenceSums(vector<int>& nums) {
        vector<int> result;
        int n = nums.size();
        for (int i = 0; i < (1 << n); ++i) {
            int sum = 0;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    sum += nums[j];
                }
            }
            result.push_back(sum);
        }
        return result;
    }
};

// Test cases
int main() {
    Solution solution;

    // Test case 1
    vector<int> nums1 = {1, 2, 3, 1, 1};
    int goal1 = 6;
    cout << "Actual Output: " << solution.minAbsDifference(nums1, goal1) << endl;

    // Test case 2
    vector<int> nums2 = {1, 2, 9, -6, 15};
    int goal2 = 7;
    cout << "Actual Output: " << solution.minAbsDifference(nums2, goal2) << endl;

    // Test case 3
    vector<int> nums3 = {1, 2, 4, 5};
    int goal3 = -1;
    cout << "Actual Output: " << solution.minAbsDifference(nums3, goal3) << endl;

    return 0;
}
