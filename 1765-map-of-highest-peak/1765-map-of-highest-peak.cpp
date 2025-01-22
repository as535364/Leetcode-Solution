// class Solution {
// public:
//     vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        
//     }
// };

class Solution {
    bool isSafe(int x, int y, int m, int n) {
        return (0 <= x && x < m && 0 <= y && y < n);
    }
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int rowSize = isWater.size(), colSize = isWater[0].size();
        vector<vector<int>> res(rowSize, vector<int>(colSize, -1));
        queue<pair<int, int>> q;

        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < colSize; ++j) {
                if (isWater[i][j] == 1) {
                    res[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int time = 1;
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                auto nowPos = q.front();
                q.pop();
                for (const auto& dir : dirs) {
                    int newPosX = dir[0] + nowPos.first, newPosY = dir[1] + nowPos.second;
                    if (isSafe(newPosX, newPosY, rowSize, colSize) && res[newPosX][newPosY] == -1) {
                        res[newPosX][newPosY] = time;
                        q.push({newPosX, newPosY});
                    }
                }
            }
            time++;
        }
        return res;
    }
};