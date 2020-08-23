class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        int hash_map[26] = {0};

        for (char c : s) {
            hash_map[c - 'a']++;
        }
        for (char c : t) {
            hash_map[c - 'a']--;
        }

        for (auto find : hash_map) {
            if (find != 0) {
                return false;
            }
        }
        return true;
    }
};