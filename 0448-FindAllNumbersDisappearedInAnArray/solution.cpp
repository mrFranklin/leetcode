class Solution {
public:
    vector<int> findDisappearedNumbers2(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int n = abs(nums[i]);
            if (n > 0 && n - 1 < nums.size() && nums[n-1] > 0) {
                nums[n-1] = -(nums[n-1]);
            }
        }

        vector<int> ret;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                ret.push_back(i + 1);
            }
        }

        return ret;
    }
};