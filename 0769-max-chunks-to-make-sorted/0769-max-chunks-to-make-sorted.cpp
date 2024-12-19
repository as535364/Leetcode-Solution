class Solution {
private:

public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxSoFar = -1, ans = 0;
        for (int i = 0; i < arr.size(); ++i) {
            maxSoFar = max(maxSoFar, arr[i]);
            if (maxSoFar == i) ans++;
        }
        return ans;
    }
};