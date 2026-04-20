class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size(), max_dis = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (colors[i] != colors[j]) {
                    max_dis = max(max_dis, abs(j - i));
                }
            }
        }
        return max_dis;
    }
};