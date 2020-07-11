class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        unordered_map<string, function<int(int, int)>> m = {
            {"+", [](int x, int y) { return x + y; }},
            {"-", [](int x, int y) { return x - y; }},
            {"*", [](int x, int y) { return x * y; }},
            {"/", [](int x, int y) { return x / y; }},
        };
        for (int i = 0; i < tokens.size(); i++) {
            if (m.find(tokens[i]) != m.end() && !st.empty()) {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int ret = m[tokens[i]](b, a);
                st.push(ret);
            } else {
                st.push(stoi(tokens[i]));
            }
        }

        return st.empty() ? 0 : st.top();
    }
};