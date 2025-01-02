class Solution {
private:
    bool count(const string &str) {
        char fC = str.front(), eC = str.back();
        bool start = (fC == 'a' || fC == 'e' || fC == 'i' || fC == 'o' || fC == 'u');
        bool end = (eC == 'a' || eC == 'e' || eC == 'i' || eC == 'o' || eC == 'u');
        return start && end;
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefix(n);
        prefix[0] = count(words[0]);
        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] + count(words[i]);
        }
        
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); ++i) {

            ans[i] = prefix[queries[i][1]];
            if (queries[i][0]) ans[i] -= prefix[queries[i][0] - 1];
        }
        return ans;
    }
};