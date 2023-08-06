class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> resMap;
        vector<int> result;
        
        for (int i = 0; i < numbers.size(); i++) {
            if (resMap.count(numbers[i])) {
                result.push_back(resMap[numbers[i]]);
                result.push_back(i+1);
            }
            else {
                resMap[target-numbers[i]] = i+1;
            }
        }
        
        return result;
    }
};