class Solution {
public:
    int search(vector<int>& nums, int target) {
        return searchIndex(nums, target, 0, nums.size()-1);
    }
private:
    int searchIndex(vector<int>& nums, int& target, int l, int r) {
        int mid = (l + r) / 2;
        
        if (nums[l] <= nums[mid] && nums[mid] <= nums[r])
            return binarySearch(nums, target, l, r);
        else if (nums[l] <= nums[mid] && nums[mid] > nums[r])
        {
            if (nums[l] <= target && target <= nums[mid])
                return binarySearch(nums, target, l, mid);
            else return searchIndex(nums, target, mid+1, r);
        }
        else {
            if (nums[mid] <= target && target <= nums[r])
                return binarySearch(nums, target, mid, r);
            else return searchIndex(nums, target, l, mid-1);
        }

    }
    
    int binarySearch(vector<int>& nums, int& target, int l, int r) {
        int mid = (l + r) / 2;
        
        while (l <= r) {
            if (nums[mid] > target)  r = mid-1;
            else if (nums[mid] < target) l = mid+1;
            else return mid;
            mid = (l + r) / 2;
        }
        return -1;
    }
};