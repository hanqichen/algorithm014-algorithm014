class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.empty() || s.size() < 2) {
            return 0;
        }

        vector<int> dp(s.size(), 0);
        int res = 0;

        for (int k = 1; k < s.size(); k++) {
            if (s[k] == ')') {
                if (s[k - 1] == '(') {
                    dp[k] = (k - 2 >= 0 ? dp[k - 2] : 0) + 2;
                } else {
                    int left = k - dp[k - 1] - 1;
                    if (left >= 0 && s[left] == '(') {
                        dp[k] = (left - 1 >= 0 ? dp[left - 1] : 0) + dp[k - 1] + 2;
                    }
                }
            }
            res = max(res, dp[k]);
        }
        return res;

    }
};