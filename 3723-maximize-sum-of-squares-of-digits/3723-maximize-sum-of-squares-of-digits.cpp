class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        vector<int> res(num);
        for (int i = 0; i < num; ++i) {
            if (sum >= 9) {
                res[i] = 9;
                sum -= 9;
            }
            else {
                res[i] = sum;
                sum -= sum;
                break;
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