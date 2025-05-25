class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int res = 0;
        unordered_map<string, int> counts;
        bool twinFlag = false;

        for (const string &word : words) {
            string reverseStr(word.rbegin(), word.rend());
            if (counts.find(reverseStr) != counts.end()) {
                res += 4;
                if (--counts[reverseStr] == 0) counts.erase(reverseStr);
            }
            else {
                ++counts[word];
            }
        }

        int maxTwinCount = 0;
        for (const auto &[word, count] : counts) {
            if (word[0] == word[1]) {
                maxTwinCount = max(maxTwinCount, count);
            }
        }
        return res + maxTwinCount * 2;
    }
};