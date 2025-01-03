class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {

        int n = s.length(), start = 0;
        for (const auto &sh : shift) {
            int dir = sh[0], amount = sh[1];
            if (dir) start -= amount;
            else start += amount;
        }
        start = ((start % n) + n) % n;
        return s.substr(start) + s.substr(0, start);
    }
};