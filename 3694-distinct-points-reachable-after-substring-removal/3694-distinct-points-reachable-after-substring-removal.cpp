class Solution {
public:
    int distinctPoints(string s, int k) {
        int x = 0, y = 0;
        set<pair<int, int>> seen;
        seen.insert({0, 0});
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
            seen.insert({x, y});
        }
        return seen.size();
    }
};