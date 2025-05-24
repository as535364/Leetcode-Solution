class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> res;
        for (int i = 0; i < words.size(); ++i) {
            for (char c : words[i]) if (c == x) {
                res.push_back(i);
                break;
            }
        }
        return res;
    }
};