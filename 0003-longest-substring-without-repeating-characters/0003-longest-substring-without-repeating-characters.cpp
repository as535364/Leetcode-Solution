class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, ans = 0;
        unordered_map<char, int> hashMap;
        for (int r = 0; r < s.size(); ++r) {
            if (hashMap.find(s[r]) != hashMap.end()) {
                l = max(l, hashMap[s[r]] + 1);
            }
            hashMap[s[r]] = r;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};