class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        vector<int> res;
        for (int i = 0; i < num; ++i) {
            if (sum >= 9) {
                res.push_back(9);
                sum -= 9;
            }
            else {
                res.push_back(sum);
                sum -= sum;
            }
        }

        if (sum) return "";

        string res_str;
        for (int x : res) {
            res_str += to_string(x);
        }
        return res_str;
    }
};