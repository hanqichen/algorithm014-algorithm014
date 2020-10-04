class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ans = 0;
        for (int k = 0; k < 8 * sizeof(uint32_t); k++) {
            ans = (ans << 1) + (n & 1);
            n = n >> 1;
        }
        return ans;
    }
};