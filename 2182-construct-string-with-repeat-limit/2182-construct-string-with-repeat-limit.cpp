class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        string res;
        vector<int> cnt(26);
        for (char c : s) cnt[c - 'a']++;

        priority_queue<pair<char, int>> pq;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i]) pq.push({i + 'a', cnt[i]});
        }
        
        char lastChar = '-';
        int lastCharRepeat = 0;

        while (!pq.empty()) {
            bool popTwice = false;
            char repeatChar = '-';
            int repeatCharCnt = 0;
            if (pq.top().first == lastChar && lastCharRepeat == repeatLimit) {
                repeatChar = pq.top().first;
                repeatCharCnt = pq.top().second;
                pq.pop();
                popTwice = true;
                lastCharRepeat = 0;
            }
            if (popTwice && pq.empty()) break;

            auto [c, cnt] = pq.top();
            pq.pop();
            res += c;
            if (c != lastChar) lastCharRepeat = 0;

            if (popTwice) {
                pq.push({repeatChar, repeatCharCnt});
            }
            lastChar = c;
            lastCharRepeat++;

            if (cnt > 1) pq.push({c, cnt - 1});
        }
        return res;
    }
};