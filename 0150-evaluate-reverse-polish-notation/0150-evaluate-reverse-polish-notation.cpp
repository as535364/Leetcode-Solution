class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;

        for (string &token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int b = stoi(st.top()); st.pop();
                int a = stoi(st.top()); st.pop();
                
                if (token == "+") {
                    st.push(to_string(a + b));
                }
                else if (token == "-") {
                    st.push(to_string(a - b));
                }
                else if (token == "*") {
                    st.push(to_string(a * b));
                }
                else {
                    st.push(to_string(a / b));
                }
            }
            else {
                st.push(token);
            }
        }
        return stoi(st.top());
    }
};