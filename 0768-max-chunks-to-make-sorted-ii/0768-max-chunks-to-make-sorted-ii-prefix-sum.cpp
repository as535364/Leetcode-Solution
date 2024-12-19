class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> sortedArr = arr;
        sort(begin(sortedArr), end(sortedArr));
        vector<long long> prefixSum(sortedArr.size());

        for (int i = 0; i < prefixSum.size(); ++i) {
            prefixSum[i] = sortedArr[i];
            if (i > 0) prefixSum[i] += prefixSum[i - 1];
        }

        int ans = 0;
        long long prefix = 0;
        for (int i = 0; i < arr.size(); ++i) {
            prefix += arr[i];
            if (prefix == prefixSum[i]) ans++;
        }
        return ans;
    }
};