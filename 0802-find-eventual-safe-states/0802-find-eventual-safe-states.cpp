class Solution {
private:
    vector<int> vis, inStack;
    bool inCycle(const vector<vector<int>> &graph, int x) {
        if (inStack[x]) return true;
        if (vis[x]) return false;

        inStack[x] = vis[x] = true;
        for (int neighbor : graph[x]) {
            if (inCycle(graph, neighbor)) return true;
        }
        
        inStack[x] = false;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
        int n = graph.size();
        vis.resize(n);
        inStack.resize(n);

        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (!inCycle(graph, i)) res.push_back(i);
        }
        return res;

    }
};