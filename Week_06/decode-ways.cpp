class Solution {
public:
    bool checkTwoChar(char first, char second) {
        if (first - '0' == 1) {
            return true;
        }
        if (first - '0' == 2 && second - '0' < 7) {
            return true;
        }
        return false;
    }

    bool checkSingleChar(char first) {
        if (first == '0') {
            return false;
        }
        return true;
    }
    int numDecodings(string s) {
        vector<int> dp(s.size() + 1, 0);
        if (!checkSingleChar(s[0])) {
            return 0;
        }
        dp[0] = dp[1] = 1;

        for (int k = 1; k < s.size(); k++) {
            bool single = checkSingleChar(s[k]);
            bool second = checkTwoChar(s[k - 1], s[k]);
            if (single && second) {
                dp[k + 1] = dp[k] + dp[k - 1];
            } else if (!single && !second) {
                return 0;
            } else {
                dp[k + 1] = single ? dp[k] : dp[k - 1];
            }
        }
        return dp[s.size()];
    }
};