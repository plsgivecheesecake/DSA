class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> frequency;
        for (int num : nums) frequency[num]++;
        std::sort(nums.begin(), nums.end(), [&frequency](int a, int b){
            if (frequency[a] < frequency[b]) return true;
            else if (frequency[a] > frequency[b]) return false;
            else return a > b;
        });
        return nums;
    }
};