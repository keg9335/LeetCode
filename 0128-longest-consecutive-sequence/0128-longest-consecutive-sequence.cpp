#define INT_MAX 1000000000
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        set<int> sortedNums (nums.begin(), nums.end());
        
        int maxCons = 1, cons = 1;
        int current = INT_MAX;
        for (auto i = sortedNums.begin(); i != sortedNums.end(); i++) {
            if (current + 1 == *i) {
                cons++;
            }
            else {
                if (maxCons < cons)
                    maxCons = cons;
                cons = 1;
            }
            current = *i;
        }
        if (maxCons < cons) maxCons = cons;
        return maxCons;        
    }    
};