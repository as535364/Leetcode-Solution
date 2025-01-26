class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<int> deg(n);
        for (int i = 0; i < n; ++i) {
            ++deg[favorite[i]];
        }

        // topological sort 
        queue<int> q;
        vector<int> depth(n);
        for (int i = 0; i < n; ++i) {
            if (deg[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int node = q.front(); q.pop();
            int f = favorite[node];
            depth[f] = max(depth[f], depth[node] + 1);
            if(--deg[f] == 0) {
                q.push(f);
            }
        }

        // find cycle
        int maxCycleLen = 0, maxMutalLen = 0;
        for (int i = 0; i < n; ++i) {
            if (deg[i] == 0) continue; // pruned
            int cycleLen = 0, node = i;
            while (deg[node] != 0) {
                deg[node] = 0;
                node = favorite[node];
                cycleLen++;
            }

            if (cycleLen > 2) {
                maxCycleLen = max(maxCycleLen, cycleLen);
            }
            else {
                maxMutalLen += 2 + depth[i] + depth[favorite[i]];
            }
        }
        return max(maxMutalLen, maxCycleLen);
    }
};