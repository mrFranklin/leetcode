class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 0) {
            return {};
        }

        sort(intervals.begin(), intervals.end());
    
        vector<vector<int>> ret;
        vector<int> v = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            if (v[1] >= intervals[i][1]) {
                continue;
            }
            if (v[1] >= intervals[i][0]) {
                v[1] = intervals[i][1];
            } else {
                ret.push_back(v);
                v = intervals[i];
            }
        }
        ret.push_back(v);

        return ret;
    }
};