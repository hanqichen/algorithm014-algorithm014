class Solution {
public:
    bool check(string& s, int lo, int hi) {
        while (lo < hi) {
            if (s[lo++] != s[hi--]) return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int lo = 0, hi = s.size() - 1;
        while(lo < hi) {
            if (s[lo] != s[hi]) {
                return check(s, lo + 1, hi) || check(s, lo, hi - 1);
            }
            lo++;
            hi--;
        }
        return true;
    }
};