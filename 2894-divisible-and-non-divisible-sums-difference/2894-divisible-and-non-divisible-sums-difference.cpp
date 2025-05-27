class Solution {
public:
    int differenceOfSums(int n, int m) {
        int sum = (1 + n) * n / 2;
        int num2 = m * (1 + (n / m)) * (n / m) / 2;
        return sum - 2 * num2;
    }
};