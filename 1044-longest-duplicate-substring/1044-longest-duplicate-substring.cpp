class Solution {
private:
    unsigned long long p[30005], h[30005];
    const unsigned long long base = 131;

    string check(const string &s, int len) {
        int n = s.size();
        unordered_set<unsigned long long> vis;
        for (int i = 1; i + len - 1 <= n; ++i) {
            int j = i + len - 1;
            unsigned long long t = h[j] - h[i - 1] * p[len];
            if (vis.count(t)) return s.substr(i - 1, len);
            vis.insert(t);
        }
        return "";
    }
public:
    string longestDupSubstring(string s) {
        int n = s.size();

        p[0] = 1;
        for (int i = 0; i < n; ++i) {
            p[i + 1] = p[i] * base;
            h[i + 1] = h[i] * base + s[i];
        }

        int left = 1, right = n - 1;
        string res;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            string tmp = check(s, mid);
            if (!tmp.empty()) {
                res = tmp;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return res;
    }
};