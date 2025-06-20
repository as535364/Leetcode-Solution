class Solution {
public:
    int maxDistance(string s, int k) {
        int count[4] = {}, res = 0;
        for (char c : s) {
            if (c == 'N') ++count[0];
            else if (c == 'S') ++count[1];
            else if (c == 'E') ++count[2];
            else if (c == 'W') ++count[3];
            int verticalDiff = abs(count[0] - count[1]), horizontalDiff = abs(count[2] - count[3]);
            int verticalMin = min(count[0], count[1]), horizontalMin = min(count[2], count[3]);
            res = max(res, verticalDiff + horizontalDiff + 2 * min(k, verticalMin + horizontalMin));
        }
        return res;
    }
};