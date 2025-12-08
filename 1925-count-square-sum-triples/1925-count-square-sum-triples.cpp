class Solution {
public:
    int countTriples(int n) {
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                int k = sqrt(i * i + j * j);
                if (k <= n && i * i + j * j == k * k) {
                    ++res;
                }
            }
        }
        return res * 2;
    }
};