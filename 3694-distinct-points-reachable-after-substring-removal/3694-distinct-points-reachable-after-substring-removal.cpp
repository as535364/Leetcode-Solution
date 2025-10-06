class Solution {
public:
    int distinctPoints(string s, int k) {
        // int x = 0, y = 0;
        // set<pair<int, int>> seen;
        // seen.insert({0, 0});
        long long x = 0, y = 0, n = s.size();
        unordered_set<long long> seen;
        seen.insert((x + n) << 32 | (y + n));
        for (int i = k; i < s.size(); ++i) {
            switch (s[i]) {
                case 'U': ++y; break;
                case 'D': --y; break;
                case 'L': --x; break;
                case 'R': ++x; break;
            }

            switch (s[i - k]) {
                case 'U': --y; break;
                case 'D': ++y; break;
                case 'L': ++x; break;
                case 'R': --x; break;
            }
            seen.insert((x + n) << 32 | (y + n));
        }
        return seen.size();
    }
};