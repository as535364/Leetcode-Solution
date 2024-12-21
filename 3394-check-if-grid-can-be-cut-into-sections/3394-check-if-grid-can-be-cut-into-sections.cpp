class Solution {
private:
    bool check(const vector<vector<int>> &cord) {
        int cnt = cord.size();
        int s = cord[0][0], e = cord[0][1];

        for (int i = 1; i < cord.size(); ++i) {
            if (e > cord[i][0]) {
                --cnt; 
            }
            e = max(cord[i][1], e);
        }
        return cnt >= 3;
    }
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        int len = rectangles.size();
        vector<vector<int>> xCord(len), yCord(len);
        for (int i = 0; i < len; ++i) {
            const auto rectangle = rectangles[i];
            xCord[i] = {rectangle[0], rectangle[2]};
            yCord[i] = {rectangle[1], rectangle[3]};
        }
        sort(begin(xCord), end(xCord));
        sort(begin(yCord), end(yCord));
        return check(xCord) || check(yCord);
    }
};