class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<bool> check(nums.size()-1);
        int result = 0;
        for (int val : nums) {
            if (!check[val]) check[val] = true;
            else {
                result = val;
                break;
            }
        }
        return result;
    }
};