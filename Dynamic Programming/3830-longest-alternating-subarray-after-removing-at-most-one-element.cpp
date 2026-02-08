class Solution {
public:
    int longestAlternating(vector<int>& nums) {
        int n = nums.size();
        int prev_up0 = 1, prev_up1 = 1, prev_down0 = 1, prev_down1 = 1;
        int pp_up = 1, pp_down = 1 , ans = 1;

        for (int i = 1; i < n; i++) {
            int up0 = 1, up1 = 1, down1 = 1, down0 = 1;

            if (nums[i] > nums[i - 1]) {
                up0 = max(up0, 1 + prev_down0);
                up1 = max(up1, 1 + prev_down1);
            } else if (nums[i] < nums[i - 1]) {
                down0 = max(down0, 1 + prev_up0);
                down1 = max(down0, 1 + prev_up1);
            }

            if (i >= 2) {
                if (nums[i] > nums[i - 2]) {
                    up1 = max(up1, 1 + pp_down);
                } else if (nums[i] < nums[i - 2]) {
                    down1 = max(down1, 1 + pp_up);
                }
            }

            ans = max({ans , up0 , up1 , down1  ,down0});

            pp_up = prev_up0;
            pp_down = prev_down0;

            prev_up0 = up0; 
            prev_up1 = up1;
            prev_down0 = down0;
            prev_down1 = down1;
        }

        return ans;
    }
};