class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        else if (n <= 2) return 1;
        
        int a = 0, b = 1, c = 1, d = a + b + c;
        
        for (int i = 0; i < n - 3; ++i) {
            a = b;
            b = c;
            c = d;
            d = a + b + c;
        }
        return d;
    }
};