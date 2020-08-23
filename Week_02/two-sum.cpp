class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> res;

        for (int k = 0; k < nums.size(); k++) {
            if (map.count(nums[k])) {
                res.push_back(map[nums[k]]);
                res.push_back(k);
                return res;
            }
            map[target - nums[k]] = k;
        }

        return res;

    }
};