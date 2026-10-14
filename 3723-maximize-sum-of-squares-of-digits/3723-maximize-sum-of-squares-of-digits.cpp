class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > num * 9) return "";

        string ans(sum / 9, '9');
        
        if (sum % 9) {
            ans += '0' + sum % 9;
        }
        ans.append(num - (int)ans.size(), '0');
        return ans;
    }
};