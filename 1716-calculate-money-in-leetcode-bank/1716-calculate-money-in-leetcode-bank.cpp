class Solution {
public:
    int totalMoney(int n) {
        int start = 0, res = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 7 == 0) ++start;
            res += start + i % 7;
        }
        return res;
    }
};