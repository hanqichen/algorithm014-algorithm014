class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int max_row = matrix.size() - 1;
        int max_col = matrix[0].size() - 1;
        int lo = 0;
        int hi = max_row;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (target <= matrix[mid][max_col]) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        int select_row = lo;
        lo = 0;
        hi = max_col;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (target == matrix[select_row][mid]) {
                return true;
            }
            if (target > matrix[select_row][mid]) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return false;

    }
};