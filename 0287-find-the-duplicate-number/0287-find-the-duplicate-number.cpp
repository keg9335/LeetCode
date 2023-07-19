class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size()-1;
        vector<bool> check(n);
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