using tiii = tuple<int, int, int>;
using pii = pair<int, int>;

class Solution {
private:
    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int qLen = queries.size(), m = grid.size(), n = grid[0].size();
        vector<pii> queriesSorted(qLen);
        vector<int> res(qLen);

        for (int i = 0; i < qLen; ++i) {
            queriesSorted[i] = {queries[i], i};
        }
        sort(queriesSorted.begin(), queriesSorted.end());

        priority_queue<tiii, vector<tiii>, greater<tiii>> pq;
        pq.push({grid[0][0], 0, 0});
        grid[0][0] = -1;

        int cnt = 0;
        for (auto [limit, idx] : queriesSorted) {
            if (pq.empty()) res[idx] = cnt;
            while (!pq.empty()) {
                auto [val, x, y] = pq.top();
                if (val >= limit) break;
                pq.pop();
                ++cnt;
                
                for (auto &dir : dirs) {
                    int nx = x + dir[0], ny = y + dir[1];
                    if (0 <= nx && nx < m && 0 <= ny && ny < n && grid[nx][ny] != -1) {
                        pq.push({grid[nx][ny], nx, ny});
                        grid[nx][ny] = -1;
                    }
                }
            }
            res[idx] = cnt;
        }
        return res;
    }
};