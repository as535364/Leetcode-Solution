class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for (const string& o : operations) {
            if (o[0] == '+' || o[2] == '+') ++x;
            else --x;
        }
        return x;
    }
};