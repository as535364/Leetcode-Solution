class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        string res;

        for (char c : s) {
            if (c != ')') st.push(c);
            else {
                string rev_str;
                while (st.top() != '(') {
                    rev_str.push_back(st.top());
                    st.pop();
                }
                st.pop();
                for (char c1 : rev_str) st.push(c1);
            }
        }
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};