class Solution {
private:
    const int inf = INT_MAX >> 1;
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size(), resDis = INT_MAX, resIdx = -1;
        auto bfs = [&](int x) -> vector<int> {
            vector<int> res(n, inf);
            int dis = 0;
            queue<int> q;
            q.push(x);

            while (!q.empty()) {
                int levelSize = q.size();
                for (int i = 0; i < levelSize; ++i) {
                    int now = q.front(); q.pop();
                    res[now] = dis;
                    if (edges[now] != -1 && res[edges[now]] == inf) q.push(edges[now]);
                }
                dis++;
            }
            return res;
        };

        vector<int> res1 = bfs(node1), res2 = bfs(node2);
        for (int i = n - 1; i >= 0; --i) {
            if (res1[i] == inf || res2[i] == inf) continue;
            if (resDis >= max(res1[i], res2[i])) {
                resDis = max(res1[i], res2[i]);
                resIdx = i;
            }
        }
        return resIdx;
    }
};