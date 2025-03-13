class Solution {
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    long long atLeastKConsonants(const string &word, int k) {
        long long res = 0;
        int consonantsCnt = 0, left = 0;
        unordered_map<char, int> vowelCnt;

        for (char c : word) {
            if (isVowel(c)) {
                ++vowelCnt[c];
            }
            else {
                ++consonantsCnt;
            }

            while (vowelCnt.size() == 5 && consonantsCnt >= k) {
                char remove = word[left];
                if (isVowel(remove) && --vowelCnt[remove] == 0) {
                    vowelCnt.erase(remove);
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