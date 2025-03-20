class DSU {
private:
    int n;
    vector<int> rank, parent;
public:
    DSU (int n) {
        rank.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
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
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DSU dsu(n);
        vector<int> componentCost(n, -1);

        for(const auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            dsu.merge(u, v);
        }

        for(const auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            int p = dsu.find(u);
            componentCost[p] &= w;
        }

        vector<int> ans(query.size());
        for (int i = 0; i < query.size(); ++i) {
            const auto &q = query[i];
            int s = dsu.find(q[0]), t = dsu.find(q[1]);
            if (s != t) ans[i] = -1;
            else ans[i] = componentCost[s];
        }
        return ans;
    }
};