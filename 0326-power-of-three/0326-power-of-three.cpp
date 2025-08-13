class Solution {
public:
    bool isPowerOfThree(int n) {
        while (n) {
            if (n % 3 != 0) break;
            else n /= 3;
        }
        return n == 1;
    }
};