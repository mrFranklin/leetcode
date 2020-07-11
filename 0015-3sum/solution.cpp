class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) {
            return vector<vector<int>>();
        }
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-2; i++) {
            // twoSum
            int target = 0 - nums[i];
            int left = i + 1;
            int right = nums.size() - 1;
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int sum = nums[i] + nums[left] + nums[right]
            while (left < right) {
                if (sum == 0) {
                    // find one
                    vector<int> v = vector<int>{nums[i], nums[left], nums[right]};
                    ret.push_back(v);
                    while (left < right && nums[left] == nums[left+1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right-1]) {
                        right--;
                    }
                    left++;
                    right--;              
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return ret;
    }
};