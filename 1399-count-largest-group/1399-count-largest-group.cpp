class Solution {
private:
    int digit(int x) {
        int sum = x % 10;
        while (x /= 10) {
            sum += x % 10;
        }
        return sum;
    }
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> digitsGroupsize;
        for (int i = 1; i <= n; ++i) {
            int d = digit(i);
            ++digitsGroupsize[d];
        }
        int resSize = 0, resCnt = 0;
        for (auto [d, size] : digitsGroupsize) {
            if (size > resSize) {
                resSize = size;
                resCnt = 1;
            }
            else if (size == resSize) {
                ++resCnt;
            }
        }
        return resCnt;
    }
};