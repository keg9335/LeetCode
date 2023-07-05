class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size(), rowInd = findRow(matrix, target);
        int l = 0, r = n-1, mid = n / 2;
        
        while (l <= r) {
            if (matrix[rowInd][mid] > target)  r = mid-1;
            else if (matrix[rowInd][mid] < target) l = mid+1;
            else return true;
            mid = (l + r) / 2;
        }   
        return false;
    }
private:
    int findRow(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int l = 0, r = m-1, mid = m / 2;
        
        while (l <= r) {
            if (matrix[mid][0] > target)  r = mid-1;
            else if (matrix[mid][0] < target) l = mid+1;
            else return mid;
            mid = (l + r) / 2;
        }
        return mid;
    }
};