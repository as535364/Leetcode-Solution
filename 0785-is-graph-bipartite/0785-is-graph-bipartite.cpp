class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for (int i = 0; i < n; ++i) {
            if (color[i] != -1) continue;
            stack<int> st;
            st.push(i);
            color[i] = 1;
            while (!st.empty()) {
                int node = st.top(); st.pop();
                for (int neighbor : graph[node]) {
                    if (color[neighbor] == color[node]) return false;
                    if (color[neighbor] == -1) {
                        color[neighbor] = 1 ^ color[node];
                        st.push(neighbor);
                    }
                }
            }
        }      
        return true;
    }
};
