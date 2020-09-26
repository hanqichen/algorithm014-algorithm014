class Solution {

    struct TrieNode {
        map<char, TrieNode*> children;
        int end;
        TrieNode():end(0) {};
    };
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if (board.empty() && board[0].empty()) {
            return res;
        }
        int row = board.size();
        int col = board[0].size();

        TrieNode* root = new TrieNode();
        for (auto word : words) {
            TrieNode* cur = root;
            for (auto c : word) {
                if (cur->children.count(c) == 0) {
                    cur->children[c] = new TrieNode();
                }
                cur = cur->children[c];
            }
            cur->end = 1;
        }

        string output;
        for (int r = 0; r < row; r++) {
            for (int k = 0; k < col; k++) {
                if (root->children.count(board[r][k]) != 0) {
                    _dfs(res, board, root, output, r, k);
                }
            }
        }

        return res;
    }

private:

    vector<int> dp_x = {0, 0, 1, -1};
    vector<int> dp_y = {1, -1, 0, 0};
    void _dfs(vector<string>& res, vector<vector<char>>& board, TrieNode* root ,string output, int x, int y) {
        char temp = board[x][y];
        root = root->children[temp];

        board[x][y] = '.';
        output.push_back(temp);
        if (root->end != 0) {
            res.push_back(output);
            root->end = 0;
        }

        for (int k = 0; k < dp_x.size(); k++) {
            int tmp_x = x + dp_x[k];
            int tmp_y = y + dp_y[k];

            if (tmp_x >= 0 && tmp_y >= 0 && tmp_x < board.size() && tmp_y < board[0].size() && board[tmp_x][tmp_y] != '.' && root->children.count(board[tmp_x][tmp_y]) != 0) {
                _dfs(res, board, root, output, tmp_x, tmp_y);
            }
        }

        output.pop_back();
        board[x][y] = temp;
    }

};