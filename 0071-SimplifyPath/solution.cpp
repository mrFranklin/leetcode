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
    // mine 慢
    string simplifyPath1(string path) {
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

    // from yxc
    string simplifyPath(string path) {
        path += "/";
        string s, res;
        for (auto c : path) {
            if (res.empty()) res += c;
            if (c != '/') s += c;
            else {
                if (s == "..") {
                    if (res.size() > 1) {
                        res.pop_back();
                        while (res.back() != '/') res.pop_back();
                    }
                } else if (s != "" && s != ".") {
                    res += s + '/';
                }
                s = "";
            }
        }
        if (res.size() > 1) res.pop_back();
        return res;
    }
};
