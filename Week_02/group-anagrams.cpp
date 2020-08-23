class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> map;
        vector<vector<string>> ans;

        for (string s : strs) {
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            if (map.find(tmp) != map.end()) {
                ans[map[tmp]].push_back(s);
            } else {
                map[tmp] = ans.size();
                ans.push_back(vector<string>{s});
            }
        }
        return ans;
    }
};