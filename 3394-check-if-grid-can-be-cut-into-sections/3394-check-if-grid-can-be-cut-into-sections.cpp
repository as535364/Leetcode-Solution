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
        vector<vector<int>> xCord, yCord;
        for (const auto &rectangle : rectangles) {
            xCord.push_back({rectangle[0], rectangle[2]});
            yCord.push_back({rectangle[1], rectangle[3]});
        }
        sort(begin(xCord), end(xCord));
        sort(begin(yCord), end(yCord));
        return check(xCord) || check(yCord);
    }
};