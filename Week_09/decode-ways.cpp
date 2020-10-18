class Solution {
public:
    bool checkSingleChar(char c) {
        if (c == '0') {
            return false;
        }
        return true;
    }

    bool checkTwoChar(char first, char second) {
        if (first == '1') {
            return true;
        }
        if (first == '2' && second < '7') {
            return true;
        }
        return false;
    }

    int numDecodings(string s) {
        int n = s.size();
        if (!checkSingleChar(s[0])) return 0;

        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;

        for (int k = 2; k <= n; k++) {
            bool single = checkSingleChar(s[k - 1]);
            bool second = checkTwoChar(s[k - 2], s[k - 1]);
            if (single && second) {
                dp[k] = dp[k - 1] + dp[k - 2];
            } else if (!single && !second) {
                dp[k] = 0;
            } else {
                dp[k] = single ? dp[k - 1] : dp[k - 2];
            }
        }

        return dp[n];
    }
};