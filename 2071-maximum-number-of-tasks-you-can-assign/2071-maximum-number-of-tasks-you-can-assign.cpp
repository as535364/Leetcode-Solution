class Solution {
private:
    bool isOK(int cntAtLeast, vector<int>& tasks, 
                vector<int>& workers, int pills, int strength) {
        multiset<int> ws(workers.begin(), workers.begin() + cntAtLeast);
        for (int i = cntAtLeast - 1; i >= 0; --i) {
            if (*ws.rbegin() >= tasks[i]) {
                auto it = --ws.end();
                ws.erase(it);
            }
            else {
                if (pills <= 0) return false;
                auto it = ws.lower_bound(tasks[i] - strength);
                if (it == ws.end()) return false;
                --pills;
                ws.erase(it);
            }
        }
        return true;
    }
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end(), greater<int>());

        int left = 0, right = min(tasks.size(), workers.size());

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isOK(mid, tasks, workers, pills, strength)) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return right;
    }
};