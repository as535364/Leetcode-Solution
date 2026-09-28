class Solution {
public:
    int maxDepth(string s) {
        int nowNestSize = 0, ans = 0;
        for (char c : s) {
            if (c == '(') {
                ++nowNestSize;
            }
            else if (c == ')') {
                ans = max(ans, nowNestSize);
                --nowNestSize;
            }
        }
        return ans;
    }
};