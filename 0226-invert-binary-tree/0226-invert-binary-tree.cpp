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
    TreeNode* invertTree(TreeNode* root) {
        root = invertLeftRight(root);
        return root;      
    }
private:
    TreeNode* invertLeftRight(TreeNode* root) {
        if (!root) return root;

        TreeNode* temp = root->left;
        if (root->right) 
            root->left = invertLeftRight(root->right);
        else root->left = root->right;

        if (temp) 
            root->right = invertLeftRight(temp);
        else root->right = temp;
    
        return root;
    }
};