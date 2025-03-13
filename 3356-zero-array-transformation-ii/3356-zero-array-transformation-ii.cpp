class Solution {
private:
    bool isOK(const vector<int>& nums, const vector<vector<int>>& queries, int k) {
        int n = nums.size();
        vector<int> prefix(n + 1);
        for (int i = 0; i < k; ++i) {
            const auto &query = queries[i];
            int l = query[0], r = query[1], val = query[2];
            prefix[l] += val;
            prefix[r + 1] -= val;
        }
        // for (int i = 0; i < n; ++i) cout << prefix[i] << ' ';
        // cout << endl;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += prefix[i];
            if (sum < nums[i]) return false;
        }
        return true;
    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int l = 0, r = queries.size();
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (isOK(nums, queries, m)) {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return r == queries.size() ? -1 : l;
    }
};
// [7,6,8]
// [[0,0,2],[0,1,5],[2,2,5],[0,2,4]]
// expect: 4
