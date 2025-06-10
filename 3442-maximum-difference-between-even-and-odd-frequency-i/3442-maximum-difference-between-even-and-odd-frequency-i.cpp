class Solution {
public:
    int maxDifference(string s) {
        vector<int> cnts(26);
        for (char c : s) {
            ++cnts[c - 'a'];
        }

        int maxOddFrequency = 0, minEvenFrequency = 100;
        for (int i = 0; i < 26; ++i) {
            if (cnts[i] % 2) maxOddFrequency = max(maxOddFrequency, cnts[i]);
            else if (cnts[i] != 0) minEvenFrequency = min(minEvenFrequency, cnts[i]);
        }
        return maxOddFrequency - minEvenFrequency;
    }
};