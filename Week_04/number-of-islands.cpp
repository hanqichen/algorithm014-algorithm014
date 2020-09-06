class Solution {
public:
    void DFS(vector<vector<char>>& grid, int row, int col) {
        if (row >= grid.size() || col >= grid[0].size() || row < 0 || col < 0 || grid[row][col] == '0') {
            return;
        }
        grid[row][col] = '0';

        DFS(grid, row + 1, col);
        DFS(grid, row - 1, col);
        DFS(grid, row, col + 1);
        DFS(grid, row, col - 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;

        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if ('1' == grid[row][col]) {
                    count++;
                    DFS(grid, row, col);
                }
            }
        }
        return count;
    }
};