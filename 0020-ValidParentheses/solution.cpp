class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> m = {
            {')', '('}, 
            {'}', '{'}, 
            {']', '['}
        };
        std::stack<char> cache;
        for (int i = 0; i < s.length(); i++) {
            if (m.find(s[i]) != m.end()) {
                if (cache.empty() || cache.top() != m[s[i]]) {
                    return false;
                }
                cache.pop();
            } else {
                cache.push(s[i]);
            }
        }
        return cache.empty();
    }
}; 