class DSU {
private:
    int n;
    vector<int> parent, rank;
public:
    DSU(int n): n(n) {
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }
    int find(int x) {
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
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu(1001);
        for (const auto &e : edges) {
            int a = e[0], b = e[1];
            if (!dsu.merge(a, b)) return {a, b};
        }
        return {-1, -1};
    }
};