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
private:
    int cycleStart = -1;
    void dfs(int src, vector<vector<int>>& graph, vector<int>& parent) {
        for (int neighbor : graph[src]) {
            if (parent[neighbor] == -1) {
                parent[neighbor] = src;
                dfs(neighbor, graph, parent);
            }
            else if (parent[src] != neighbor && cycleStart == -1) {
                cycleStart = neighbor;
                parent[neighbor] = src;
            }
        }
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // DSU dsu(edges.size() + 1);
        // for (const auto &e : edges) {
        //     int a = e[0], b = e[1];
        //     if (!dsu.merge(a, b)) return e;
        // }
        // return {};


        // dfs
        int n = edges.size();
        vector<vector<int>> graph(n + 1);
        vector<int> parent(n + 1, -1);

        for (const auto &e : edges) {
            int a = e[0], b = e[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        
        dfs(1, graph, parent);
        unordered_set<int> nodesInCycle;
        int node = cycleStart;
        do {
            nodesInCycle.insert(node);
            node = parent[node];
        } while (node != cycleStart);

        for (int i = n - 1; i >= 0; --i) {
            int a = edges[i][0], b = edges[i][1];
            if (nodesInCycle.count(a) && nodesInCycle.count(b)) return edges[i];
        }
        return {};
    }
};