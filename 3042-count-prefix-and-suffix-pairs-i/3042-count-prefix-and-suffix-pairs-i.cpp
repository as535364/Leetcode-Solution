class Solution {
private:
    bool isPrefixAndSuffix(const string &a, const string &b) {
        return b.starts_with(a) && b.ends_with(a);
    }
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size(), res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                res += isPrefixAndSuffix(words[i], words[j]);
            }
        }
        return res;
    }
};