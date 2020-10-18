class Solution {
public:
    int myAtoi(string s) {
        int index = 0;
        int n = s.size();

        while (index < n && isspace(s[index])) index++;

        int sign = 1;
        if (s[index] == '-' || s[index] == '+') {
            sign = s[index] == '-' ? -1 : 1;
            index++;
        }

        int res = 0;
        int digit = 0;
        while (index < n) {
            digit = s[index] - '0';
            if (digit < 0 || digit > 9) break;

            if (INT_MAX / 10 < res || (INT_MAX / 10 == res && INT_MAX % 10 < digit)) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            res = res * 10 + digit;
            index++;
        }
        return res * sign;
    }
};