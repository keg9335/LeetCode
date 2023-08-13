/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int goodNodes(TreeNode* root) {
        int max = -1e4, count = 0;
        checkGooeNode(root, max, count);
        
        return count;                        
    }
private:
    void checkGooeNode(TreeNode* root, int max, int& count) {
        if (root->val >= max) {
            max = root->val;
            count++;
            cout<<root->val<<endl;
        }
        
        if (root->left) checkGooeNode(root->left, max, count);
        if (root->right) checkGooeNode(root->right, max, count);
        
    }
};