class Solution {
public:
    int maxArea(vector<int>& height) {
        long l = 0, r = height.size()-1;
        long size = 0;
        
        while (l < r) {
            long minH = min(height[l], height[r]);
            if (size < minH * (r - l))
                size = minH * (r - l);
            if (height[l] < height[r])
                l++;
            else r--;
        }
        
        return size;
    }
};