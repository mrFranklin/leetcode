class Solution {
public:
    string print(stack<string> st) {
        if (st.empty()) {
            return "";
        }
        string ch = st.top();
        st.pop();
        return print(st) + ch;
    }
    string simplifyPath(string path) {
        if (path == "") {
            return "";
        }
        stringstream ss(path);
        string str = "";
        stack<string> st;
        while (getline(ss, str, '/')) {
            if (str == "" || str == "." ) {
                continue;
            } else if (str == "..") {
                if (!st.empty()) {
                    st.pop();
                }
            } else {
                st.push("/" + str);
            }
        }
        if (st.empty()) {
            st.push("/");
        }
        
        return print(st);
    }
};