class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size(), clock = 0;
        vector<int> in(n), out(n), xr(n);
        vector<vector<int>> g(n);

        for (const auto &edge : edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }

        auto dfs = [&](this auto&& self, int x, int fa) -> void {
            in[x] = ++clock;
            xr[x] = nums[x];
            for (int neighbor : g[x]) {
                if (neighbor == fa) continue;
                self(neighbor, x);
                xr[x] ^= xr[neighbor];
            }
            out[x] = clock;
        };

        dfs(0, -1);


        auto isAncestor = [&] (int x, int y) -> bool {
            return in[x] < in[y] && out[y] <= out[x];
        };

        int res = numeric_limits<int>::max();
        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int x, y, z;
                if (isAncestor(i, j)) { // xr[0] ^ xr[i], xr[i] ^ xr[j], xr[j]
                    x = xr[0] ^ xr[i], y = xr[i] ^ xr[j], z = xr[j];
                }
                else if (isAncestor(j, i)) {
                    x = xr[0] ^ xr[j], y = xr[j] ^ xr[i], z = xr[i];
                }
                else {
                    x = xr[0] ^ xr[i] ^ xr[j], y = xr[i], z = xr[j];
                }
                res = min(res, max({x, y, z}) - min({x, y, z}));
                if (res == 0) return 0;
            }
        }
        return res;
    }
};