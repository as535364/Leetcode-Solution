class Solution {
private:
    int dst;
    vector<vector<int>> graph;
    
    bool dfs(int node, vector<int>& vis) {
        if (node == dst && graph[node].empty()) return true;
        else if (graph[node].empty()) return false;

        vis[node] = 1;
        for (int nei : graph[node]) {
            if (vis[nei] == 2) continue;

            if (vis[nei] == 1) return false;
            if(!dfs(nei, vis)) return false;
        }
        vis[node] = 2;
        return true;
    }
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        graph.resize(n);
        dst = destination;
        for (const auto &e : edges) {
            graph[e[0]].push_back(e[1]);
        }
        
        vector<int> vis(n);
        vis[source] = 1;
        return dfs(source, vis);
    }
};