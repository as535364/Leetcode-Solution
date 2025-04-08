class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<bool> vis(n);
        for(auto edge : edges){
            int x = edge[0], y = edge[1];
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        int cnt = 0;
        for(int i = 0; i < n; ++i){
            if(!vis[i]){
                ++cnt;
                dfs(graph, vis, i);
            }
        }
        return cnt;
    }
    void dfs(vector<vector<int>> &graph, vector<bool> &vis, int node){
        for(int neighbor : graph[node]){
            if(!vis[neighbor]){
                vis[neighbor] = true;
                dfs(graph, vis, neighbor);
            }
        }
    }
};