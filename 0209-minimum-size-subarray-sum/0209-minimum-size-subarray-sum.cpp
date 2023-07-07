class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, sum = 0, ans = INT_MAX, len = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            while (sum >= target) {
                len = i - left + 1;
                ans = min(ans, len);
                sum -= nums[left];
                left++;
            }
        }
        if (ans == INT_MAX) {
            return 0;
        } else {
            return ans;
        }
    }
};
