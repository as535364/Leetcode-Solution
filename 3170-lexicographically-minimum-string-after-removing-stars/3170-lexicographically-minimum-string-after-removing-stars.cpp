#include <ranges>
class Solution {
public:
    string clearStars(string s) {
        stack<int> stacks[32];
        for (auto &&[index, c] : views::enumerate(s)) {
            if (c != '*') {
                stacks[c - 'a'].push(index);
                continue;
            }
            for (auto &st : stacks) {
                if (!st.empty()) {
                    s[st.top()] = '*';
                    st.pop();
                    break;
                }
            }
        }
        s.erase(ranges::remove(s, '*').begin(), s.end());
        return s;
    }
};