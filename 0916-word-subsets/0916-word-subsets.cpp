class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int len1 = words1.size(), len2 = words2.size();
        vector<int> words2Max(26);

        for (string &word : words2) {
            vector<int> count(26);
            for (char c : word) {
                ++count[c - 'a'];
            }
            for (int i = 0; i < 26; ++i) {
                words2Max[i] = max(words2Max[i], count[i]);
            }
        }

        vector<string> res;
        for (string &word : words1) {
            vector<int> count(26);
            for (char c : word) {
                ++count[c - 'a'];
            }

            bool isUniversal = true;
            for (int i = 0; i < 26; ++i) {
                if (count[i] < words2Max[i]) isUniversal = false;
            }
            if (isUniversal) res.push_back(word);
        }
        return res;
    }
};