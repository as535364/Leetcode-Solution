class DSU {
private:
    int n;
    vector<int> parent, rank;
public:
    DSU (int n): n(n), parent(n), rank(n, 1) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }
    int find (int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (rank[x] > rank[y]) swap(x, y);
        rank[y] += rank[x];
        parent[x] = y;
        return true;
    }
    int findSize(int x) {
        x = find(x);
        return rank[x];
    }
};

class Solution {
private:
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    bool isValid(int nr, int nc, int m, int n, const vector<vector<int>>& grid) {
        return 0 <= nr && nr < m && 0 <= nc && nc < n && grid[nr][nc];
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        DSU dsu(m * n);
        int res = 0;
        bool hasZero = false;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (!grid[r][c]) {
                    hasZero = true;
                    continue;
                }
                for (auto &d : dir) {
                    int nr = r + d[0], nc = c + d[1];
                    if (!isValid(nr, nc, m, n, grid)) continue;
                    dsu.merge(r * m + c, nr * m + nc);
                }
                res = max(res, dsu.findSize(r * m + c));
            }
        }
        if (!hasZero) return res;
        
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c]) continue;
                unordered_set<int> uniqueRoot;
                for (auto &d : dir) {
                    int nr = r + d[0], nc = c + d[1];
                    if (!isValid(nr, nc, m, n, grid)) continue;
                    int nowRoot = dsu.find(nr * m + nc);
                    if (!uniqueRoot.count(nowRoot)) {
                        uniqueRoot.insert(nowRoot);
                    }
                }
                int sum = 1;
                for (int root : uniqueRoot) sum += dsu.findSize(root);
                res = max(res, sum);
            }
        }
        return res;
    }
};