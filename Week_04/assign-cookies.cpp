class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int res = 0;

        for (int g_idx = 0, s_idx = 0; g_idx < g.size() && s_idx < s.size(); s_idx++) {
            if (g[g_idx] <= s[s_idx]) {
                res++;
                g_idx++;
            }
        }

        return res;
    }
};