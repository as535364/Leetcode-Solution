class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int operations = 0, ans = 0;
        for (int i = 0; i < k; ++i) {
            if (blocks[i] == 'W') ++operations;
        }
        ans = operations;

        for (int i = k; i < blocks.size(); ++i) {
            if (blocks[i] == 'W') ++operations;
            if (blocks[i - k] == 'W') --operations;
            ans = min(ans, operations);
        }
        return ans;
    }
};