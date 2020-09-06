class Solution {
public:
    bool canJump(vector<int>& nums) {
        int can_reachable = nums.size() - 1;

        for (int k = nums.size() - 1; k >=0; k--) {
            if (k + nums[k] >= can_reachable) {
                can_reachable = k;
            }
        }

        return can_reachable == 0;

    }
};