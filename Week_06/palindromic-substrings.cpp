class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;

        for (int k = 0; k < s.size() * 2 - 1; k++) {
            int lo = k / 2;
            int hi = lo + k % 2;

            while (lo >= 0 && hi < s.size() && s[lo] == s[hi]) {
                ans++;
                lo--;
                hi++;
            }
        }

        return ans;
    }
};