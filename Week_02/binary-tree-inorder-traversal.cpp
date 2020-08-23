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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;

        if (root != nullptr) {
            st.push(root);
        }

        while(!st.empty()) {
            TreeNode* cur = st.top();
            st.pop();
            if (cur != nullptr) {
                if (cur->right) st.push(cur->right);
                st.push(cur);
                st.push(nullptr);
                if (cur->left) st.push(cur->left);
            } else {
                ans.push_back(st.top()->val);
                st.pop();
            }
        }

        return ans;
    }
};