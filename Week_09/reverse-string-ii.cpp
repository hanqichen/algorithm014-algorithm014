class Solution {
public:
    string reverseStr(string s, int k) {
        if (s.empty()) return s;
        int start = 0;

        while (start + k < s.size()) {
            reverse(s, start, start + k);
            start += 2 * k;
        }

        if (start < s.size()) {
            reverse(s, start, s.size());
        }

        return s;
    }

    void reverse(string& s, int begin, int end) {
        if (s.empty()) return;

        for (int lo = begin, hi = end - 1; lo < hi; lo++, hi--) {
            swap(s[lo], s[hi]);
        }
    }
};