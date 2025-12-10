class Solution {
private:
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool isValid(int r, int c, int m, int n) {
        return 0 <= r && r < m && 0 <= c && c < n;
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        vector<vector<bool>> vis(m, vector<bool>(n));
        queue<pair<int, int>> q;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    vis[i][j] = true;
                }
            }
        }

        int dis = 0;
        while (!q.empty()) {
            int level_size = q.size();
            for (int i = 0 ; i < level_size; ++i) {
                auto [r, c] = q.front();
                q.pop();

                if (mat[r][c] == 1) {
                    res[r][c] = dis;
                }

                for (int dir_i = 0; dir_i < 4; ++dir_i) {
                    int nr = r + dirs[dir_i][0], nc = c + dirs[dir_i][1];
                    if (!isValid(nr, nc, m, n) || vis[nr][nc]) continue;
                    q.push({nr, nc});
                    vis[nr][nc] = true;
                }
            }
            ++dis;
        }
        return res;
    }
};