class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.empty() || s.size() < 2) {
            return 0;
        }

        int n = s.size();
        int res = 0;
        vector<int> dp(n, 0);

        for (int k = 1; k < n; k++) {
            if (s[k] == ')') {
                if (s[k - 1] == '(') {
                    dp[k] = (k - 2 >= 0 ? dp[k - 2] : 0) + 2;
                } else {
                    int left_idx = k - dp[k - 1] - 1;
                    if (left_idx >= 0 && s[left_idx] == '(') {
                        dp[k] = (left_idx - 1 >= 0 ? dp[left_idx - 1] : 0) + dp[k - 1] + 2;
                    }
                }
            }
            res = max(res, dp[k]);
        }

        return res;
    }
};