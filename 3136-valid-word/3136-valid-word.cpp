class Solution {
public:
    bool isValid(string word) {
        bool vowel = false, consonant = false;
        for (char c : word) {
            if (!isalnum(c)) return false;
            if (isdigit(c)) continue;

            c = tolower(c);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') vowel |= true;
            else consonant |= true;
        }
        return vowel && consonant && word.length() >= 3;
    }
};