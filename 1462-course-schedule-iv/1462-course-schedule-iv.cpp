class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> graph(numCourses, vector<bool>(numCourses));
        for (auto &p : prerequisites) {
            graph[p[0]][p[1]] = true;
        }

        for (int k = 0; k < numCourses; ++k) {
            for (int i = 0; i < numCourses; ++i) {
                for (int j = 0; j < numCourses; ++j) {
                    graph[i][j] = graph[i][j] || graph[i][k] && graph[k][j];
                }
            }
        }

        vector<bool> res;
        for (auto &q : queries) {
            res.push_back(graph[q[0]][q[1]]);
        }
        return res;
    }
};