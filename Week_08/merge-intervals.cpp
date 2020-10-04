class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& left, vector<int>& right){ return left[0] < right[0];});

        vector<vector<int>> res;
        int last_idx = -1;
        for (auto item : intervals) {
            if (last_idx == -1 || res[last_idx][1] < item[0]) {
                res.push_back(item);
                last_idx++;
            } else {
                res[last_idx][1] = max(res[last_idx][1], item[1]);
            }
        }
        return res;

    }
};