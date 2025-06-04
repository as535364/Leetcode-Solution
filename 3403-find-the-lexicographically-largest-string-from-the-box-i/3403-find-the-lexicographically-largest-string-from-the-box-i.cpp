class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1) return word;
        int maxLen = word.size() - numFriends + 1, wordLen = word.length();
        string res;

        for (int i = 0; i < word.size(); ++i) {
            res = max(res, word.substr(i, min(wordLen - i, maxLen)));
        }
        return res;
    }
};