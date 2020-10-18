class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> need(26, 0);
        vector<int> windows(26, 0);
        int expect = 0;
        int satisfy = 0;
        vector<int> res;

        for (auto c : p) {
            if (need[c - 'a'] == 0) {
                expect++;
            }
            need[c - 'a']++;
        }

        int lo = 0, hi = 0;
        while (hi < s.size()) {
            char c = s[hi];
            hi++;
            windows[c - 'a']++;
            if (need[c - 'a'] > 0 && windows[c - 'a'] == need[c - 'a']) satisfy++;

            while (hi - lo >= p.size()) {
                if (expect == satisfy) {
                    res.push_back(lo);
                }

                char d = s[lo];
                lo++;
                if (need[d - 'a'] > 0 && windows[d - 'a'] == need[d - 'a']) {
                    satisfy--;
                }
                windows[d - 'a']--;
            }
        }

        return res;
    }
};