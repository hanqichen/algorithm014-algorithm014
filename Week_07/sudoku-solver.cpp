class Solution {
public:
    bool backtrack(vector<vector<char>>& board, vector<vector<int>>& row, vector<vector<int>>& col, vector<vector<int>>& bok, vector<pair<int, int>>& empty_list, int idx) {
        if (idx == empty_list.size()) {
            return true;
        }

        int r = empty_list[idx].first;
        int c = empty_list[idx].second;
        int b = r / 3 * 3 + c / 3;

        for (int k = 1; k < 10; k++) {
            if (row[r][k] == 0 && col[c][k] == 0 && bok[b][k] == 0) {
                board[r][c] = '0' + k;
                row[r][k]++;
                col[c][k]++;
                bok[b][k]++;
                if (backtrack(board, row, col, bok, empty_list,idx + 1)) {
                    return true;
                }
                row[r][k] = 0;
                col[c][k] = 0;
                bok[b][k] = 0;
                board[r][c] = '.';
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();
        vector<vector<int>> row(9, vector<int>(10, 0));
        vector<vector<int>> col(9, vector<int>(10, 0));
        vector<vector<int>> bok(9, vector<int>(10, 0));

        vector<pair<int, int>> empty_list;

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (board[r][c] != '.') {
                    int tmp = board[r][c] - '0';
                    row[r][tmp]++;
                    col[c][tmp]++;
                    bok[r / 3 * 3 + c / 3][tmp]++;
                } else {
                    empty_list.push_back(make_pair(r, c));
                }
            }
        }

        backtrack(board, row, col, bok, empty_list, 0);
    }
};