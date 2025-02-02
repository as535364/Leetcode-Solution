class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        // what the hell is it?
        sort(envelopes.begin(), envelopes.end(), [](const auto &a, const auto &b){
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });

        vector<int> res;

        for (int i = 0; i < n; ++i) {
            if (res.empty() || res.back() < envelopes[i][1]) res.push_back(envelopes[i][1]);
            else *lower_bound(res.begin(), res.end(), envelopes[i][1]) = envelopes[i][1];
        }
        return res.size();
    }
};