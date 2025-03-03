class Solution {
public:
    int minSwaps(vector<int>& data) {
        int count1 = accumulate(data.begin(), data.end(), 0);
        int window = 0;
        for (int i = 0; i < count1; ++i) {
            if (data[i] == 0) ++window;
        }

        int ans = window;
        for (int i = count1; i < data.size(); ++i) {
            window = window - data[i] + data[i - count1];
            ans = min(ans, window);
        }
        return ans;
    }
};