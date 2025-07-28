class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> res;
        for (int num : arr) {
            if (!num) {
                res.push_back(0);
                res.push_back(0);
            }
            else {
                res.push_back(num);
            }
        }
        for (int i = 0; i < arr.size(); ++i) {
            arr[i] = res[i];
        }
    }
};