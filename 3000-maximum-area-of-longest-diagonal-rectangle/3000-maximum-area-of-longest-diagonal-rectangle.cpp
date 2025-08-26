class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        sort(dimensions.begin(), dimensions.end(), [](const auto& a, const auto &b){
            return a[0] * a[0] + a[1] * a[1] != b[0] * b[0] + b[1] * b[1] ? 
                    a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1] :
                    a[0] * a[1] < b[0] * b[1];
        });
        return dimensions.back()[0] * dimensions.back()[1];
    }
};