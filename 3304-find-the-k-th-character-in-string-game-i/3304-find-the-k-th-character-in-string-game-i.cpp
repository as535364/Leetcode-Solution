class Solution {
public:
    char kthCharacter(int k) {
        string res = "a";

        while (res.length() < k) {
            string tmp = res;
            for (char &c : tmp) {
                if (c == 'z') c = 'a';
                else c += 1;
            }
            res += tmp;
        }
        return res[k - 1];
    }
};