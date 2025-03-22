class DSU {
public:
    vector<int> rank, parent;
    DSU(int n): rank(n, 1), parent(n, -1) {}
    int find(int x) {
        if (parent[x] == -1) return x;
        return parent[x] = find(parent[x]);
    }
    bool merge (int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        rank[x] += rank[y];
        parent[y] = x;
        return true;
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        for (const auto &e : edges) {
            int u = e[0], v = e[1];
            dsu.merge(u, v);
        }
        
        int res = 0;
        vector<int> component(n);
        for (const auto &e : edges) {
            int p = dsu.find(e[0]);
            int fullEdgeCnt = dsu.rank[p];
            fullEdgeCnt = fullEdgeCnt * (fullEdgeCnt - 1) / 2;
            if(++component[p] == fullEdgeCnt) ++res;
        }

        for (int i = 0; i < n; ++i) {
            int p = dsu.find(i);
            if (dsu.rank[p] == 1) ++res;
        }

        return res;
    }
};