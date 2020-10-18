class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> cnt(26, 0);

        for (auto c : s) cnt[c - 'a']++;

        for (int k = 0; k < s.size(); k++) {
            if (cnt[s[k] - 'a'] == 1) {
                return k;
            }
        }
        return -1;
    }
};