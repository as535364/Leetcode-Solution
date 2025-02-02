class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        // what the hell is it?
        sort(envelopes.begin(), envelopes.end(), [](const auto &a, const auto &b){
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });

        vector<int> res;
        vector<int> secondDim;
        for (int i = 0; i < n; ++i) secondDim.push_back(envelopes[i][1]);

        for (int i = 0; i < n; ++i) {
            if (res.empty() || res.back() < secondDim[i]) res.push_back(secondDim[i]);
            else *lower_bound(res.begin(), res.end(), secondDim[i]) = secondDim[i];
        }
        return res.size();
    }
};