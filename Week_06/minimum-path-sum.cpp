class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        for (int row_idx = 1; row_idx < row; row_idx++) {
            grid[row_idx][0] += grid[row_idx - 1][0];
        }
        for (int col_idx = 1; col_idx < col; col_idx++) {
            grid[0][col_idx] += grid[0][col_idx - 1];
        }


        for (int row_idx = 1; row_idx < row; row_idx++) {
            for (int col_idx = 1; col_idx < col; col_idx++) {
                grid[row_idx][col_idx] += min(grid[row_idx - 1][col_idx], grid[row_idx][col_idx - 1]);
            }
        }

        return grid[row - 1][col - 1];

    }
};