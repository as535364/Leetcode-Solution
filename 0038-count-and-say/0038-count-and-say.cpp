class Solution {
private:
    string dfs(int n) {
        if (n == 1) return "1";
        string res = dfs(n - 1);
        cout << n - 1 << ' ' << res << endl;
        return RLE(res);
    }

    string RLE(string &s) {
        char lastChar = '\0';
        int repeaTimes = 1;
        s.push_back('#');
        string res;
        for (char c : s) {
            if (c != lastChar && lastChar != '\0') {
                res += to_string(repeaTimes) + lastChar;
                repeaTimes = 1;
            }
            else if (c == lastChar) {
                repeaTimes++;
            }
            lastChar = c;
        }
        return res;
    }
public:
    string countAndSay(int n) {
        return dfs(n);
    }
};