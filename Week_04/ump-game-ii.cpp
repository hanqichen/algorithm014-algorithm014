class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0;
        int last_end = 0;
        int cur_end = 0;

        for (int k = 0; k < nums.size() - 1; k++) {
            cur_end = max(cur_end, k + nums[k]);
            if (k == last_end) {
                last_end = cur_end;
                res++;
                if (last_end > nums.size() - 1) {
                    break;
                }
            }
        }

        return res;

    }
};