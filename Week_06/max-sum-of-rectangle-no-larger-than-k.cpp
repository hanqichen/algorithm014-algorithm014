class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int row = matrix.size();
        if (row == 0) {
            return 0;
        }

        int col = matrix[0].size();
        vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));

        for (int rdx = 1; rdx <= row; rdx++) {
            for (int cdx = 1; cdx <= col; cdx++) {
                dp[rdx][cdx] = dp[rdx][cdx - 1] + matrix[rdx - 1][cdx - 1];
            }
        }

        int res = INT_MIN;
        for (int lo = 1; lo <= col; lo++) {
            for (int hi = lo; hi <= col; hi++) {
                int cur = 0;
                set<int> st;
                st.insert(0);
                for (int r = 1; r <= row; r++) {
                    cur += dp[r][hi] - dp[r][lo - 1];
                    auto p = st.lower_bound(cur - k);
                    if (p != st.end()) res = max(res, cur - *p);
                    st.insert(cur);
                }
            }
        }
        return res;

    }
};