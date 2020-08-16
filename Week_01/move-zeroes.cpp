class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0;

        for (int fast = 0; fast < nums.size(); fast++) {
            if (nums[fast] != 0) {
                if (fast != slow) {
                    nums[slow] = nums[fast];
                    nums[fast] = 0;
                }
                slow++;
            }
        }
    }
};