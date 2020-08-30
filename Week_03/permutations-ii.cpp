class Solution {
public:
    void backtrack(vector<vector<int>>& ans, vector<int>& nums, vector<int>& output, vector<bool> visit, int depth, int end) {
        if (depth == end) {
            ans.push_back(output);
            return;
        }

        for (int idx = 0; idx < end; idx++) {
            if (idx > 0 && nums[idx] == nums[idx - 1] && !visit[idx - 1]) {
                continue;
            }

            if (!visit[idx]) {
                output.push_back(nums[idx]);
                visit[idx] = true;
                backtrack(ans, nums, output, visit, depth + 1, end);
                visit[idx] = false;
                output.pop_back();
            }
        }

    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> output;
        vector<bool> visit(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtrack(res, nums, output, visit, 0, nums.size());
        return res;
    }
};