#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

struct Solution {

    vector<int> *generateSubsetSums(const vector<int>& arrayPart) {
        int halfLength = arrayPart.size();
        vector<int> *subsetSums = new vector<int>[halfLength + 1]; // Create an array of lists to store subset sums based on their size

        // Initialize each list in the subsetSums array
        for (int i = 0; i <= halfLength; i++) {
            subsetSums[i] = vector<int>();
        }

        // Generating all subsets using an iterative method (power set)
        for (int mask = 0; mask < (1 << halfLength); mask++) {
            int subsetSize = 0, subsetSum = 0, currentMask = mask, index = 0;
            while (currentMask != 0) {
                if ((currentMask & 1) == 1) { // Check if the lowest bit is 1 (part of the subset)
                    subsetSize++; // Increment the size of the current subset
                    subsetSum += arrayPart[index]; // Add the current element to the subset sum
                }
                index++;
                currentMask >>= 1; // Shift right to process the next bit
            }
            subsetSums[subsetSize].push_back(subsetSum); // Add the sum of this subset to the corresponding list
        }
        return subsetSums;
    }

    bool splitArraySameAverage(vector<int>& nums) {
        int arrayLength = nums.size();
        if (arrayLength == 1) return false; // A single element cannot be split into two subsets
        if (arrayLength == 2) return nums[0] == nums[1]; // With two elements, they must be equal to split equally

        int halfLength = arrayLength / 2;
        int totalSum = accumulate(nums.begin(), nums.end(), 0); // Calculate the total sum of the array

        // Generate subset sums for the first half and second half of the array
        vector<int> *firstHalfSubsetSums = generateSubsetSums(vector<int>(nums.begin(), nums.begin() + halfLength + 1));
        vector<int> *secondHalfSubsetSums = generateSubsetSums(vector<int>(nums.begin() + halfLength + 1, nums.end()));

        // Sort each list in the second half subset for binary search later
        for (int i = 0; i < halfLength; i++) {
            sort(secondHalfSubsetSums[i].begin(), secondHalfSubsetSums[i].end());
        }

        // Check if we can find two subsets (one from each half) that satisfy the condition
        for (int i = 0; i < halfLength + 1; i++) {
            for (int sum1 : firstHalfSubsetSums[i]) {
                for (int j = 0; j < halfLength; j++) {
                    // Skip cases where the subset size is 0 or equal to the total length
                    if (i + j == 0 || i + j == arrayLength) continue;

                    // Calculate the required sum for the second subset
                    double requiredSum = (1.0 * totalSum * (i + j)) / arrayLength - sum1;
                    if (ceil(requiredSum) != requiredSum) continue; // Check if requiredSum is an integer

                    // Check if the required sum exists in the second half subsets using binary search
                    if (binary_search(secondHalfSubsetSums[j].begin(), secondHalfSubsetSums[j].end(), static_cast<int>(requiredSum))) {
                        return true; // If found, return true
                    }
                }
            }
        }
        return false;
    }
};

// Example usage
int main() {
    Solution solution;

    // Example 1
    vector<int> nums1 = {1, 5, 3, 5, 6};
    cout << "Example 1: " << solution.splitArraySameAverage(nums1) << endl;

    // Example 2
    vector<int> nums2 = {3, 5, 6, 4, 2, 10};
    cout << "Example 2: " << solution.splitArraySameAverage(nums2) << endl;

    // Example 3
    vector<int> nums3 = {4, 8, 16, 24, 32, 40};
    cout << "Example 3: " << solution.splitArraySameAverage(nums3) << endl;

    return 0;
}
