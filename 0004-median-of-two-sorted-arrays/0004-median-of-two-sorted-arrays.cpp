class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int total = m + n;
        
        if (m > n) return findMedianSortedArrays(nums2, nums1);
        
        int lowbound = 0, highbound = m;
        int midInd1 = 0, midInd2 = 0, l1 = 0, r1 = 0, l2 = 0, r2 = 0;
        double result = 0;
        
        while (lowbound <= highbound) {
            midInd1 = (lowbound + highbound) / 2;
            midInd2 = total/2 - midInd1;
            
            l1 = midInd1 > 0 ? nums1[midInd1-1] : INT_MIN;
            r1 = midInd1 < m ? nums1[midInd1] : INT_MAX;
            l2 = midInd2 > 0 ? nums2[midInd2-1] : INT_MIN;
            r2 = midInd2 < n ? nums2[midInd2] : INT_MAX;
            
            if (l1 <= r2 && l2 <= r1) {
                if (total % 2 == 0) {
                    result = (max(l1, l2) + min(r1, r2)) / 2.0;
                }
                else {
                    result = min(r1, r2);
                }
                break;
            }
            else if (r1 < l2) {
                lowbound = midInd1 + 1;
            }
            else {
                highbound = midInd1 - 1;
            }  
        }
        return result;
    }
};