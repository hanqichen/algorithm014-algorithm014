class Solution {
public:
    string reverseWords(string s) {
        int start = 0;

        while (start < s.size()) {
            while (start < s.size() && isspace(s[start])) start++;
            int end = start;
            while (end < s.size() && !isspace(s[end])) end++;
            reverse(s, start, end);
            start = end;
        }

        return s;
    }

    void reverse(string& s, int start, int end) {
        for (int lo = start, hi = end - 1; lo < hi; lo++, hi--) {
            swap(s[lo], s[hi]);
        }
    }
};