class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string tmp;
        int idx = 1;
        while (ss >> tmp) {
            if (tmp.starts_with(searchWord)) return idx;
            idx++;
        }
        return -1;
    }
};