class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> tStack;
        int size = temperatures.size();
        bool isfound = false;
        
        vector<int> result(size);
        
        for (int i = size-1; i >= 0; i--) {
            isfound = false;
            while (!tStack.empty()) {
                if(tStack.top().first <= temperatures[i]) {
                    tStack.pop();
                }
                else {
                    isfound = true;
                    break;
                }
            }
            
            result[i] = isfound? tStack.top().second-i : 0;
            tStack.push({temperatures[i], i});
        }
        
        return result;       
        
        
        // int size = temperatures.size();
        // vector<int> result(size);
        // for (int i = size-1; i >= 0; i--) {
        //     int day = 0;
        //     result[i] = day;
        //     for (int j=i+1; j<size; j++) {
        //         day++;
        //         if (temperatures[i] < temperatures[j]) {
        //             result[i] = day;
        //             break;
        //         }
        //     }
        // }    
        // return result;
    }
};