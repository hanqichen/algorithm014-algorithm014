class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> ans;

        for (int k = 0; k < nums.size(); k++) {
            if (map.find(nums[k]) != map.end()) {
                ans.push_back(map[nums[k]]);
                ans.push_back(k);
                return ans;
            }
            int res = target - nums[k];
            map[res] = k;
        }

        return ans;
    }
};