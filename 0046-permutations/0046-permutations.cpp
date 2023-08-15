class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> elements;
        permute(nums, elements, result);

        return result;
    }

    void permute(vector<int> nums, vector<int>& elements, vector<vector<int>>& result) {
        if (nums.empty()) 
            result.push_back(elements);
            
        for (int i = 0; i < nums.size(); i++) {
            vector<int> tempNums(nums);
            elements.push_back(nums[i]);
            tempNums.erase(tempNums.begin()+i);
            permute(tempNums, elements, result);
            elements.pop_back();
        }
    }
};