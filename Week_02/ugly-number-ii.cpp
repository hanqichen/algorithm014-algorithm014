class Solution {
public:
    int nthUglyNumber(int n) {
        vector<long long> dp(n);
        int dp_2, dp_3, dp_5;
        dp_2 = dp_3 = dp_5 = 0;
        dp[0] = 1;

        for (int k = 1; k < n; k++) {
            dp[k] = min(2 * dp[dp_2], min(3 * dp[dp_3], 5 * dp[dp_5]));
            if (dp[k] == 2 * dp[dp_2]) dp_2++;
            if (dp[k] == 3 * dp[dp_3]) dp_3++;
            if (dp[k] == 5 * dp[dp_5]) dp_5++;
        }

        return dp[n - 1];
    }
};