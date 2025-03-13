class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size(), res = 0, nowWindowAlternating = 0;
        for (int i = 1; i < k; ++i) {
            if (colors[i] ^ colors[i - 1]) ++nowWindowAlternating;
        }
        if (nowWindowAlternating == k - 1) ++res;

        for (int i = k; i < n + k - 1; ++i) {
            if (colors[(i - k) % n] ^ colors[(i - k + 1) % n]) --nowWindowAlternating;
            if (colors[i % n] ^ colors[(i - 1) % n]) ++nowWindowAlternating;
            if (nowWindowAlternating == k - 1) ++res;
        }
        return res;
    }
};