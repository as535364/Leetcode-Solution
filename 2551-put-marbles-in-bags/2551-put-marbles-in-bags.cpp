class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if(k == 1 || k == n)return 0;
        vector<int> bars;
        for(int i = 0; i + 1 < n; ++i){
            bars.push_back(weights[i] + weights[i + 1]);
        }
        sort(bars.begin(), bars.end());
        long long maxAns = 0, minAns = 0;
        for(int i = 0; i < k - 1; ++i){
            maxAns += bars[n - 2 - i];
            minAns += bars[i];
        }
        return maxAns - minAns;
    }
};