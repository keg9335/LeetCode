class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        set<vector<int>> setSum;
        int l = 0, r = nums.size() - 1;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() - 2; i++) {
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    setSum.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if (nums[i] + nums[j] + nums[k] < 0) {
                    j++;
                }
                else { k--; }
            }
        }

        for (auto v : setSum) {
            result.push_back(v);
        }

        return result;
    }
};
