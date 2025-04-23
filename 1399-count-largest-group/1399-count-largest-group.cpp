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
        int resSize = 0;
        for (int i = 1; i <= n; ++i) {
            int d = digit(i);
            ++digitsGroupsize[d];
            resSize = max(resSize, digitsGroupsize[d]);
        }
        
        int resCnt = 0;
        for (auto [_, size] : digitsGroupsize) {
            if (size == resSize) {
                ++resCnt;
            }
        }
        return resCnt;
    }
};