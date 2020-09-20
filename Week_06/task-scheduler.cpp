class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int len = tasks.size();
        vector<int> nums(26, 0);
        for (auto task : tasks) {
            nums[task - 'A']++;
        }
        sort(nums.begin(), nums.end(), [](int &x, int &y) {return x > y;});

        int cnt = 1;
        while (cnt < nums.size() && nums[cnt] == nums[0]) cnt++;

        return max(len, (n + 1) * (nums[0] - 1) + cnt);

    }
};