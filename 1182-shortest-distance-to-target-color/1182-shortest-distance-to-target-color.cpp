class Solution {
private:
    int inf = 5e5;
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        int n = colors.size();
        vector<vector<int>> dis(n, vector<int>(3, inf));

        int lastColors[3] = {-1, -1, -1};
        for (int i = 0; i < n; ++i) {
            lastColors[colors[i] - 1] = i;
            for (int j = 0; j < 3; ++j) {
                if (lastColors[j] == -1) continue;
                dis[i][j] = min(dis[i][j], i - lastColors[j]);
            }
        }

        lastColors[0] = lastColors[1] = lastColors[2] = -1;
        for (int i = n - 1; i >= 0; --i) {
            lastColors[colors[i] - 1] = i;
            for (int j = 0; j < 3; ++j) {
                if (lastColors[j] == -1) continue;
                dis[i][j] = min(dis[i][j], lastColors[j] - i);
            }
        }

        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            int idx = queries[i][0], color = queries[i][1] - 1;
            ans[i] = dis[idx][color] == inf ? -1 : dis[idx][color];
        }
        return ans;
    }
};