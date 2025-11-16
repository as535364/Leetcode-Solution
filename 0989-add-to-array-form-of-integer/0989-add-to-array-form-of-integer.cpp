class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> res;
        int carry = 0;
        for (int i = num.size() - 1; i >= 0; --i) {
            num[i] += (k % 10) + carry;
            k /= 10;
            carry = num[i] / 10;
            res.push_back(num[i] % 10);
        }
        
        while (k) {
            int d = k % 10 + carry;
            k /= 10;
            carry = d / 10;
            res.push_back(d % 10);
        }
                       
        if (carry) {
            res.push_back(carry);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};