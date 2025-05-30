class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size(), clock = 0;
        vector<int> in(n), out(n), xr(n);
        vector<vector<int>> graph(n);

        for (const auto &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        auto dfs = [&](this auto&& self, int x, int fa) -> void {
            in[x] = ++clock;
            xr[x] = nums[x];
            for (int neighbor : graph[x]) {
                if (neighbor == fa) continue;
                self(neighbor, x);
                xr[x] ^= xr[neighbor];
            }
            out[x] = clock;
        };

        auto isAncestor = [&](int x, int y){
            return in[x] < in[y] && out[y] <= out[x];
        };

        dfs(0, -1);

        int res = numeric_limits<int>::max();

        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int x, y, z;

                if (isAncestor(i, j)) {
                    x = xr[0] ^ xr[i], y = xr[i] ^ xr[j], z = xr[j];
                }
                else if (isAncestor(j, i)) {
                    x = xr[0] ^ xr[j], y = xr[j] ^ xr[i], z = xr[i];
                }
                else {
                    x = xr[0] ^ xr[i] ^ xr[j], y = xr[i], z = xr[j];
                }
                res = min(res, max({x, y, z}) - min({x, y, z}));
            }
        }
        return res;
    }
};
