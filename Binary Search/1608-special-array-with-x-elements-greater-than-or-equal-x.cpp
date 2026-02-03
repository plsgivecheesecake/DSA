class Solution {
public:
    int findLowerBound(vector<int>& nums, int target) {
        int L = 0, R = nums.size() - 1;
        while (L <= R) {
            int mid = (L + R) / 2;
            if (nums[mid] >= target) {
                R = mid - 1;
            }
            else {
                L = mid + 1;
            }
        }
        return L;
    }

    int specialArray(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 1; i <= n; i++) {
            int lower_bound = findLowerBound(nums, i);
            if ((n - lower_bound) == i) return i;
        }
        return -1;
    }
};