class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        int row = matrix.size();
        int col = matrix[0].size();
        int res = 0;
        vector<vector<int>> dp(row, vector<int>(col, 0));

        dp[0][0] = matrix[0][0] - '0';
        res = dp[0][0];

        for (int row_idx = 1; row_idx < row; row_idx++) {
            dp[row_idx][0] = matrix[row_idx][0] - '0';
            res = max(res, dp[row_idx][0]);
        }
        for (int col_idx = 1; col_idx < col; col_idx++) {
            dp[0][col_idx] = matrix[0][col_idx] - '0';
            res = max(res, dp[0][col_idx]);
        }

        for (int row_idx = 1; row_idx < row; row_idx++) {
            for (int col_idx = 1; col_idx < col; col_idx++) {
                if (matrix[row_idx][col_idx] != '0') {
                    dp[row_idx][col_idx] = min(min(dp[row_idx - 1][col_idx - 1], dp[row_idx - 1][col_idx]), dp[row_idx][col_idx - 1]) + 1;
                }
                res = max(res, dp[row_idx][col_idx]);
            }
        }

        return res * res;
    }
};