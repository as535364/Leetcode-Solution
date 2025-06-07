#include <ranges>
using pci = pair<char, int>;
class Solution {
public:
    string clearStars(string s) {
        priority_queue<pci, vector<pci>, decltype ([](pci &a, pci &b) -> bool {
            if (a.first != b.first) return a.first > b.first;
            else return a.second < b.second;
        })> pq;

        for (auto const [index, c] : views::enumerate(s)) {
            if (c != '*') pq.push({c, index});
            else pq.pop();
        }

        priority_queue<pci, vector<pci>, decltype ([](pci &a, pci &b) -> bool {
            return a.second > b.second;
        })> resPQ;

        while (!pq.empty()) {
            auto [c, index] = pq.top();
            pq.pop();
            resPQ.push({c, index});
        }

        string res;
        while (!resPQ.empty()) {
            char c = resPQ.top().first;
            resPQ.pop();
            res += c;
        }
        return res;
    }
};