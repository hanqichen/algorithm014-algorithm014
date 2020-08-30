class Solution {
public:
    void backtrack(vector<vector<int>>& ans, vector<int>& output, int start, int end, int k) {
        if (k == output.size()) {
            ans.push_back(output);
            return;
        }

        for (int idx = start; idx <= end; idx++) {
            output.push_back(idx);
            backtrack(ans, output, idx + 1, end, k);
            output.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> output;
        backtrack(ans, output, 1, n, k);
        return ans;
    }
};