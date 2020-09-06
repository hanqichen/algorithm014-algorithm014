class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int, int>> obstacle_set;

        for (auto item : obstacles) {
            obstacle_set.insert(make_pair(item[0], item[1]));
        }

        vector<int> dp_x = {0, 1, 0, -1};
        vector<int> dp_y = {1, 0, -1, 0};
        int res, cur_x, cur_y;
        res = cur_x = cur_y = 0;
        int direct = 0;

        for (auto item : commands) {
            if (item == -1) {
                direct = (direct + 1) % 4;
            } else if (item == -2) {
                direct = (direct + 3) % 4;
            } else {
                for (int k = 0; k < item; k++) {
                    int tmp_x = cur_x + dp_x[direct];
                    int tmp_y = cur_y + dp_y[direct];

                    if (obstacle_set.find(make_pair(tmp_x, tmp_y)) == obstacle_set.end()) {
                        cur_x = tmp_x;
                        cur_y = tmp_y;
                        res = max(res, cur_x * cur_x + cur_y * cur_y);
                    }
                }
            }
        }
        return res;

    }
};