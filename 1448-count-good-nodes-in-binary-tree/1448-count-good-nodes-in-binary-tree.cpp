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
        int maximum = -1e4, count = 0;
        checkGooeNode(root, maximum, count);
        
        return count;                        
    }
private:
    void checkGooeNode(TreeNode* root, int maximum, int& count) {
        if (root->val >= maximum) {
            maximum = root->val;
            count++;
            cout<<root->val<<endl;
        }
        
        if (root->left) checkGooeNode(root->left, maximum, count);
        if (root->right) checkGooeNode(root->right, maximum, count);
        
    }
};