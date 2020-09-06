class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int k = 1; k < prices.size(); k++) {
            if (prices[k] - prices[k - 1] > 0) res += prices[k] - prices[k - 1];
        }
        return res;
    }
};