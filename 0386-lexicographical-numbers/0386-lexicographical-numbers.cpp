class Solution {
private:
    void generateLexical(int curr, int limit, vector<int>& res) {
        if (curr > limit) return;
        res.push_back(curr);
        for (int i = 0; i < 10; ++i) {
            int newNum = curr * 10 + i;
            if (newNum <= limit) generateLexical(newNum, limit, res);
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for (int i = 1; i < 10; ++i) {
            generateLexical(i, n, res);
        }
        // int now = 1;

        // for (int i = 0; i < n; ++i) {
        //     res.push_back(now);

        //     if (now * 10 <= n) now *= 10;
        //     else {
        //         while (now % 10 == 9 || now >= n) now /= 10;
        //         now++;
        //     }
        // }
        return res;
    }
};