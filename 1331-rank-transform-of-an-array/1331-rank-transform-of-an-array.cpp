class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> tmp(arr);
        sort(tmp.begin(), tmp.end());
        auto uniqueEndIt = unique(tmp.begin(), tmp.end());
        for (int i = 0; i < n; ++i) {
            arr[i] = lower_bound(tmp.begin(), uniqueEndIt, arr[i]) - tmp.begin() + 1;
        }
        return arr;
    }
};