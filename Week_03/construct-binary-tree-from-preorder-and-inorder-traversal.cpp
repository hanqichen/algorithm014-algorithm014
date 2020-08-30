/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int pre_idx = 0;
    int in_idx = 0;
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int stop) {
        if (pre_idx == preorder.size()) {
            return nullptr;
        }

        if (inorder[in_idx] == stop) {
            in_idx++;
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[pre_idx++]);
        root->left = helper(preorder, inorder, root->val);
        root->right = helper(preorder, inorder, stop);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, inorder, INT_MIN);
    }
};