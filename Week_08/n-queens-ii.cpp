class Solution {
public:
    int totalNQueens(int n) {
        dfs(n, 0, 0, 0, 0);
        return this->res;
    }

    void dfs(int n, int row, int col, int pie, int na) {
        if (row >= n) {
            res++;
            return;
        }

        int bits = ~(col | pie | na) & ((1 << n) - 1);

        while (bits > 0) {
            int p = bits & -bits;
            dfs(n, row + 1, col | p, (pie | p) << 1, (na | p) >> 1);
            bits = bits & (bits - 1);
        }
    }

private:
    int res;
};