class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> prefix(n);

        for (const auto &shift : shifts) {
            int s = shift[0], e = shift[1], dir = shift[2];
            if (dir == 0) dir = -1;

            prefix[s] += dir;
            if (e + 1 < n) prefix[e + 1] -= dir;
        }

        for (int i = 0; i < n; ++i) {
            if (i != 0) prefix[i] += prefix[i - 1];
            s[i] = (s[i] - 'a' + prefix[i] % 26 + 26) % 26 + 'a';
        }
        return s;
    }
};