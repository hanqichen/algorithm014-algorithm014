class Solution {
public:
    string reverseOnlyLetters(string S) {
        int lo = 0;
        int hi = S.size() - 1;

        while (lo < hi) {
            while (lo < hi && !isalpha(S[lo])) lo++;
            while (lo < hi && !isalpha(S[hi])) hi--;
            swap(S[lo++], S[hi--]);
        }

        return S;

    }
};