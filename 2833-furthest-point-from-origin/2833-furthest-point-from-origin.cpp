class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int underline_cnt = 0, res = 0;
        for (char c : moves) {
            if (c == 'L') --res;
            else if (c == 'R') ++ res;
            else ++underline_cnt;
        }
        return res >= 0 ? res + underline_cnt : -res + underline_cnt;
    }
};