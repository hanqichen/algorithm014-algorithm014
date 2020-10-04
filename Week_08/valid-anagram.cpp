class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        vector<int> cnt(26, 0);

        for (auto c : s) cnt[c - 'a']++;

        for (auto c : t) cnt[c - 'a']--;

        for (int k = 0; k < 26; k++) {
            if (cnt[k] != 0) {
                return false;
            }
        }
        return true;

    }
};