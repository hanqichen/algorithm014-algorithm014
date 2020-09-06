class Solution {
public:
    void dfs(vector<vector<char>>& board, vector<int>& dp_x, vector<int>& dp_y, int x, int y) {
        int cnt = 0;
        for (int k = 0; k < dp_x.size(); k++) {
            int tmp_x = x + dp_x[k];
            int tmp_y = y + dp_y[k];
            if (tmp_x < 0 || tmp_y < 0 || tmp_x >= board.size() || tmp_y >= board[0].size()) {
                continue;
            }
            if (board[tmp_x][tmp_y] == 'M') {
                cnt++;
            }
        }

        if (cnt > 0) {
            board[x][y] = '0' + cnt;
            return;
        }

        board[x][y] = 'B';
        for (int k = 0; k < dp_x.size(); k++) {
            int tmp_x = x + dp_x[k];
            int tmp_y = y + dp_y[k];
            if (tmp_x < 0 || tmp_y < 0 || tmp_x >= board.size() || tmp_y >= board[0].size() || board[tmp_x][tmp_y] != 'E') {
                continue;
            }
            dfs(board, dp_x, dp_y, tmp_x, tmp_y);
        }
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        vector<int> dp_x = {1, -1, 0, 1, -1, 0, 1, -1};
        vector<int> dp_y = {0, 0, 1, 1, 1, -1, -1, -1};

        int x = click[0];
        int y = click[1];

        if (board[x][y] == 'M') {
            board[x][y] = 'X';
        } else {
            dfs(board, dp_x, dp_y, x, y);
        }
        return board;
    }
};