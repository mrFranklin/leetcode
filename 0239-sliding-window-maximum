class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        if (k <= 0) {
            return ret;
        }
        deque<int> dq;
        for (int i = 0; i < nums.size(); i++) {
            if (i + 1 >= k && !dq.empty() && i - k + 1 > dq.front()) {
                dq.pop_front();
            }
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            
            dq.push_back(i);
            if (i + 1 >= k) {
                ret.push_back(nums[dq.front()]);
            }
        }

        return ret;
    }
};