class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int> cnts;

        int left = 0, ans = 0;
        for (int right = 0; right < s.size(); ++right) {
            ++cnts[s[right]];
            while (cnts[s[right]] > 1) {
                --cnts[s[left]];
                ++left;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};