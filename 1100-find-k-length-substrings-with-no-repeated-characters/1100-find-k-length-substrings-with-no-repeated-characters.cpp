class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        int res = 0, left = 0;
        vector<int> cnt(26);

        for (int right = 0; right < s.size(); ++right) {
            char c = s[right];
            ++cnt[c - 'a'];

            while(cnt[c - 'a'] > 1) {
                --cnt[s[left] - 'a'];
                ++left;
            }
            if (right - left + 1 >= k) res++;
        }
        return res;
    }
};