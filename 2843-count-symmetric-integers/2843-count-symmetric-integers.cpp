class Solution {
private:
    bool isSymmetric(int x) {
        string s = to_string(x);
        int n = s.length();
        if (n % 2) return false;
        
        int firstPart = 0, secondPart = 0;
        for (int i = 0; i < n / 2; ++i) {
            firstPart += s[i] - '0';
            secondPart += s[n - i - 1] - '0';
        }
        return firstPart == secondPart;
    }
public:
    int countSymmetricIntegers(int low, int high) {
        int res = 0;
        for (int i = low; i <= high; ++i) {
            res += isSymmetric(i);
        }
        return res;
    }
};