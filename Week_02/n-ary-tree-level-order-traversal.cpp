/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        queue<Node*> q;

        if (root != nullptr) {
            q.push(root);
        }

        while(!q.empty()) {
            int size = q.size();
            vector<int> curLevel;
            for (int k = 0; k < size; k++) {
                Node* cur = q.front();
                curLevel.push_back(cur->val);
                q.pop();
                for (auto child : cur->children) {
                    q.push(child);
                }
            }
            ans.push_back(curLevel);
        }

        return ans;

    }
};