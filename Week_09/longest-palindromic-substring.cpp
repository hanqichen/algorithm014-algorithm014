class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        int max_len = 0;

        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));

        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                }

                if (dp[i][j] && j - i + 1 > max_len) {
                    res = s.substr(i, j - i + 1);
                    max_len = j - i + 1;
                }
            }
        }

        return res;

    }
};