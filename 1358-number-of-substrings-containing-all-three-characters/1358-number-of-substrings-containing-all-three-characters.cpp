class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> nextA(n, n), nextB(n, n), nextC(n, n);
        int nextAIdx = n, nextBIdx = n, nextCIdx = n;

        for (int i = n - 1; i >= 0; --i) {
            nextA[i] = nextAIdx;
            nextB[i] = nextBIdx;
            nextC[i] = nextCIdx;
            if (s[i] == 'a') nextAIdx = i;
            else if (s[i] == 'b') nextBIdx = i;
            else if (s[i] == 'c') nextCIdx = i;
        }

        int res = 0;
        for (int i = 0; i < n; ++i) {
            int minEnd = -1;
            if (s[i] == 'a') {
                minEnd = max(nextB[i], nextC[i]);
            }
            else if (s[i] == 'b') {
                minEnd = max(nextA[i], nextC[i]);
            }
            else if (s[i] == 'c') {
                minEnd = max(nextA[i], nextB[i]);
            }
            res += (n - minEnd);
        }
        return res;
    }
};