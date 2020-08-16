class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int k = digits.size() - 1; k >= 0 ; k--) {
            if (digits[k] == 9) {
                digits[k] = 0;
            } else {
                digits[k]++;
                return digits;
            }
        }

        digits.push_back(0);
        digits[0] = 1;
        return digits;

    }
};