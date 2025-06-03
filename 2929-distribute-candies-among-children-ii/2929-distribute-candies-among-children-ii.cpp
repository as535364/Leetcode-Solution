class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long count = 0;
        for (int i = 0; i <= min(n, limit); ++i) {
            count +=  max(0, min(limit, n - i) - max(0, n - i - min(n - i, limit)) + 1);
        }
        return count;
    }
};