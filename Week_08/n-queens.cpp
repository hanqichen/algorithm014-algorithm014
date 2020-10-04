class Solution {
public:
    int findPosition(int nums) {
        int pos = 0;
        int mask = 1;

        while ((nums & mask) == 0) {
            pos++;
            mask = mask << 1;
        }
        return pos;
    }

    void backtrack(vector<vector<string>>& res, vector<string>& board, int n, int row, int lie, int pie, int na) {
        if (row == board.size()) {
            res.push_back(board);
            return;
        }

        int bits = ~(lie | pie | na) & ((1 << n) - 1);

        while (bits > 0) {
            int byte_pos = bits & -bits;
            int pos = findPosition(byte_pos);
            board[row][pos] = 'Q';
            backtrack(res, board, n, row + 1, lie | byte_pos, (pie | byte_pos) << 1, (na | byte_pos) >> 1);
            board[row][pos] = '.';
            bits = bits & (bits - 1);
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        backtrack(res, board, n, 0, 0, 0, 0);
        return res;
    }


};