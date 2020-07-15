class Solution {
public:
    bool isAnagram2(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        unordered_map<char, int> cache;
        for (int i = 0; i < s.size(); i++) {
                cache[s[i]]++;
        }
        for (int i = 0; i < t.size(); i++) {
            cache[t[i]]--;
            if (cache[t[i]] < 0) {
                return false;
            }
        }
        return true;
    }
    // better
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        int cache[26] = {0};
        for (int i = 0; i < s.size(); i++) {
                cache[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++) {
            if (--cache[t[i] - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};