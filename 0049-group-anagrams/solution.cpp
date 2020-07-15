class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, int> cache;
        for (int i = 0; i < strs.size(); i++) {
            string sorted = strs[i];
            sort(sorted.begin(), sorted.end());
            if (cache.find(sorted) == cache.end()) {
                vector<string> v;
                v.push_back(strs[i]);
                ans.push_back(v);
                cache[sorted] = cache.size();
            } else {
                ans[cache[sorted]].push_back(strs[i]);
            }
        }
        return ans;
    }
};