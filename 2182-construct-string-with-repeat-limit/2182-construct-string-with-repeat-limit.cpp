class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        priority_queue<char> pq;
        vector<int> freq(26);
        for (char c : s) {
            if (!freq[c - 'a']) pq.push(c);
            ++freq[c - 'a'];
        }
        
        string res;
        while (!pq.empty()) {
            char c = pq.top();
            cout << c << endl;
            pq.pop();
            int used = min(repeatLimit, freq[c - 'a']);
            freq[c - 'a'] -= used;
            res.append(used, c);

            if (pq.empty() || freq[c - 'a'] == 0) continue;

            char next = pq.top();
            cout << next << endl;
            pq.pop();
            freq[next - 'a']--;
            res.append(1, next);

            if (freq[c - 'a']) pq.push(c);
            if (freq[next - 'a']) pq.push(next);
        }
        return res;
    }
};