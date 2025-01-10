class Solution {
private:
    vector<unordered_map<char, int>> words1Map, words2Map;
    // check b is subset of a
    bool isSubset(unordered_map<char, int> &a, unordered_map<char, int> &b) {
        for (auto &[c, freq] : b) {
            if (a[c] < freq) return false;
        }
        return true;
    }
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int len1 = words1.size(), len2 = words2.size();
        words1Map.resize(len1);
        words2Map.resize(len2);

        for (int i = 0; i < len1; ++i) {
            for (char c : words1[i]) {
                ++words1Map[i][c];
            }
        }

        unordered_map<char, int> totalWord2Map;
        for (int i = 0; i < len2; ++i) {
            for (char c : words2[i]) {
                ++words2Map[i][c];
            }
            for (auto &[c, freq] : words2Map[i]) {
                totalWord2Map[c] = max(totalWord2Map[c], freq);
            }
        }

        vector<string> res;
        for (int i = 0; i < len1; ++i) {
            if (isSubset(words1Map[i], totalWord2Map)) {
                res.push_back(words1[i]);
            }
        }
        return res;
    }
};