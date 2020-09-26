class UnionFind {
private:
    vector<int> parents;
    vector<int> weights;
    int count;
public:

    UnionFind(int nums):count(nums) {
        parents.resize(nums);
        weights.resize(nums);
        for (int k = 0; k < nums; k++) {
            parents[k] = k;
            weights[k] = 1;
        }
        count = nums;
    };

    int find(int i) {
        while(i != parents[i]) {
            parents[i] = parents[parents[i]];
            i = parents[i];
        }
        return i;
    };

    void unionset(int i, int j) {
        int rootP = find(i);
        int rootQ = find(j);
        if (rootP == rootQ) return;
        if (weights[rootQ] > weights[rootP]) {
            parents[rootP] = rootQ;
            weights[rootQ] += weights[rootP];
        } else {
            parents[rootQ] = rootP;
            weights[rootP] += weights[rootQ];
        }
        count--;
    };

    int getCount() {
        return count;
    };
};



class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        UnionFind uf(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (M[i][j] == 1) {
                    uf.unionset(i, j);
                }
            }
        }
        return uf.getCount();
    }
};