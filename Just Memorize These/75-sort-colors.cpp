// Dutch National Flag Algorithm
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int mid = 0, low = 0, high = nums.size() - 1;
        while (mid <= high) {
            if (nums[mid] == 0) { // Swap with low
                std::swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1) { // No swap
                mid++;
            }
            else { // Swap with high, but remember, high could be anything
                std::swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};