class Solution {
public:
    int distributeCandies(int n, int limit) {
        int count = 0;
        for (int i = 0; i <= min(n, limit); ++i) {
            for (int j = 0; j <= min(n - i, limit); ++j) {
                int k = n - i - j;
                if (0 <= k && k <= limit) ++count;
            }
        }
        return count;                
    }
};