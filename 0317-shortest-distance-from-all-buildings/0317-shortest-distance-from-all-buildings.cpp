class Solution {
public:
    int m, n;
    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int shortestDistance(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        vector<vector<int>> totalDis(m, vector<int>(n, 0));
        vector<vector<int>> visTimes(m, vector<int>(n, 0));
        int buildingCnt = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1){
                    ++buildingCnt;
                    bfs(grid, totalDis, visTimes, i, j);
                }
            }
        }
        int ans = INT_MAX;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 0){
                    if(visTimes[i][j] != buildingCnt)continue;
                    ans = min(ans, totalDis[i][j]);
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
    void bfs(vector<vector<int>>& grid, vector<vector<int>>& totalDis, vector<vector<int>>& visTimes, int row, int col){
        queue<vector<int>> q;
        vector<vector<bool>> vis(m, vector<bool>(n));
        vis[row][col] = true;
        q.push({row, col, 0});
        while(!q.empty()){
            auto& front = q.front();
            int row = front[0], col = front[1], step = front[2];
            q.pop();
            totalDis[row][col] += step;
            visTimes[row][col]++;
            for(auto &dir : dirs){
                int nextRow = row + dir[0], nextCol = col + dir[1];
                if(isValid(grid, nextRow, nextCol) && !vis[nextRow][nextCol]){
                    vis[nextRow][nextCol] = true;
                    q.push({nextRow, nextCol, step + 1});
                }
            }
        }
    }
    
    bool isValid(vector<vector<int>>& grid, int row, int col){
        if(row < 0 || row >= m || col < 0 || col >=n)return false;
        return grid[row][col] == 0;
    }
};