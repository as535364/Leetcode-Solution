class Solution {
private:
    vector<string> res;
    void dfs(string &curr, int idx, vector<vector<char>> &options) {
        // cout << curr << endl;
        if (idx == options.size()) {
            res.push_back(curr);
            return;
        }
        for (char c : options[idx]) {
            curr.push_back(c);
            dfs(curr, idx + 1, options);
            curr.pop_back();
        }
    }
public:
    vector<string> expand(string s) {
        vector<vector<char>> options;
        bool inCurly = false;
        vector<char> option;
        
        for (char c : s) {
            if (c == ',') continue;
            if (c != '{' && c != '}' && !inCurly) {
                options.push_back({c});
                continue;
            }
            else if (c != '{' && c != '}') {
                option.push_back(c);
                continue;
            }
            
            if (c == '{') {
                inCurly = true;
                if (!option.empty()) options.push_back(option);
                option = vector<char>();
            }
            else {
                inCurly = false;
                options.push_back(option);
                option = vector<char>();
            }
        }
        if (!option.empty()) options.push_back(option);
        
        string curr;
        dfs(curr, 0, options);
        sort(res.begin(), res.end());
        return res;
    }
};