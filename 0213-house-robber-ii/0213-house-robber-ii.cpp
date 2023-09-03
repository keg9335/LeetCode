class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        else if (nums.size() == 2) return max(nums[0], nums[1]);

        vector<int> nums1(nums.begin(), nums.end()-1);
        vector<int> nums2(nums.begin()+1, nums.end());
        
        return max(robDP(nums1), robDP(nums2));
    }
    int robDP(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++)
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        return dp[nums.size()-1];
    }
};