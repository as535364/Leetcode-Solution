class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int workersRemaining = workers.size();
        int n = workers.size(), m = bikes.size();
        vector<tuple<int, int, int>> v;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                const auto& work = workers[i], bike = bikes[j];
                int dis = abs(work[0] - bike[0]) + abs(work[1] - bike[1]);
                v.push_back({dis, i, j});
            }
        }
        sort(v.begin(), v.end());
        
        vector<int> res(n, -1);
        vector<int> bikeAssigned(m, -1);
        for (int k = 0; k < v.size(); ++k) {
            if (workersRemaining == 0) break;
            auto [dis, workerIdx, bikeIdx] = v[k];
            if (res[workerIdx] != -1) continue;
            if (bikeAssigned[bikeIdx] != -1) continue;
            res[workerIdx] = bikeIdx;
            bikeAssigned[bikeIdx] = workerIdx;
            workersRemaining--;
        }
        return res;
    }
};