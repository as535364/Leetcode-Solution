class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if (sentence1.size() != sentence2.size()) return false;
        unordered_map<string, unordered_map<string, bool>> sp;
        
        for (const auto &similarPair : similarPairs) {
            sp[similarPair[0]][similarPair[1]] = sp[similarPair[1]][similarPair[0]] = true;
        }
        
        int n = sentence1.size();
        for (int i = 0; i < n; ++i) {
            if (sentence1[i] != sentence2[i] && !sp[sentence1[i]][sentence2[i]]) {
                return false;
            }
        }
        return true;
    }
};