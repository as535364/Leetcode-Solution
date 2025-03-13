class Solution {
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    long long atLeastKConsonants(const string &word, int k) {
        long long res = 0;
        int vowelSize = 0, consonantsCnt = 0, left = 0;
        vector<int> vowelCnt(26);

        for (char c : word) {
            if (isVowel(c)) {
                ++vowelCnt[c - 'a'];
                if (vowelCnt[c - 'a'] == 1) vowelSize++;
            }
            else {
                ++consonantsCnt;
            }

            while (vowelSize == 5 && consonantsCnt >= k) {
                char remove = word[left];
                if (isVowel(remove)) {
                    --vowelCnt[remove - 'a'];
                    if (vowelCnt[remove - 'a'] == 0) vowelSize--;
                }
                else {
                    --consonantsCnt;
                }
                ++left;
            }
            res += left;
        }
        return res;
    }
public:
    long long countOfSubstrings(string word, int k) {
        return atLeastKConsonants(word, k) - atLeastKConsonants(word, k + 1);
    }
};