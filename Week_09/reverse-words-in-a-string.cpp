class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        int start = 0;
        int end = s.size() - 1;

        while (start < end && isspace(s[start])) start++;
        while (start < end && isspace(s[end])) end--;

        if (start == end) return "";

        for (int l = start; l < end;) {
            while (l <= end && isspace(s[l])) l++;
            int r = l;
            while (r <= end && !isspace(s[r])) r++;
            reverse(s.begin() + l, s.begin() + r);
            l = r;
        }

        int slow = start;
        for (int fast = start; fast <= end; fast++) {
            if (isspace(s[fast]) && isspace(s[fast - 1])) {
                continue;
            }
            s[slow++] = s[fast];
        }

        return s.substr(start, slow - start);

    }
};