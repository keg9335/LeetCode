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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return nullptr;
        TreeNode* result = new TreeNode(preorder[0]);
        if (preorder.size() == 1) return result;

        int mid = 0;

        for (int i = 0; i < preorder.size(); i++) {
            if (result->val == inorder[i]) {
                mid = i;
                break;
            }
        }    
        
        vector<int> fPre(preorder.begin()+1, preorder.begin()+mid+1);
        vector<int> rPre(preorder.begin()+mid+1, preorder.end());
        vector<int> fIn(inorder.begin(), inorder.begin()+mid);
        vector<int> rIn(inorder.begin()+mid+1, inorder.end());

        result->left = buildTree(fPre, fIn);
        result->right = buildTree(rPre, rIn);

        return result;
    }
};