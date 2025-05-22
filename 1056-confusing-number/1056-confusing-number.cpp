class Solution {
public:
    bool confusingNumber(int n) {
        vector<int> confusingMap({0, 1, -1, -1, -1, -1, 9, -1, 8, 6});
        string nStr = to_string(n), newStr = to_string(n);
        
        for (int i = 0; i < nStr.size(); ++i) {
            if (confusingMap[nStr[i] - '0']  == -1) return false;
            newStr[i] = confusingMap[nStr[i] - '0'] + '0';
        }
        reverse(newStr.begin(), newStr.end());
        return n != stoi(newStr);
    }
};