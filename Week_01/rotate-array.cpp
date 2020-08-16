class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        if (nums.size() < 2) {
            return;
        }

        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }

    void reverse(vector<int>& nums, int begin, int end) {
        int left = begin;
        int right = end;

        while(left < right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }
};