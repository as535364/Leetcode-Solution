class Solution {
public:
    int minOperations(int n) {
        int res = 0;
        while (n) {
            if (n & 1) {
                if ((n & 3) == 3) n += 1;
                else n -= 1;
                ++res;
            }
            else {
                n >>= 1;
            }
        }
        return res;
    }
};