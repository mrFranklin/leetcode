class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int i1, i2;
        int t1, t2;
        int over1, over2;
        int left, right;
        int size = nums.size();
        for (i1 = 0; i1 < size - 3; i1++) {
            if (i1 > 0 && nums[i1] == nums[i1-1]) {
                continue;
            }
            t1 = target - nums[i1];
            over1 = false;
            for (i2 = i1 + 1; i2 < size - 2; i2++) {
                if (i2 > i1 + 1 && nums[i2] == nums[i2-1]) {
                    continue;
                }
                t2 = t1 - nums[i2];
                left = i2 + 1;
                right = size - 1;
                while (left < right) {
                    if (nums[left] + nums[right] == t2) {
                        vector<int> v = {nums[i1], nums[i2], nums[left], nums[right]};
                        ans.push_back(v);
                        while (left + 1 < right && nums[left] == nums[left+1]) {
                            left++;
                        }
                        while (right - 1 > left && nums[right] == nums[right-1]) {
                            right--;
                        }
                        left++;
                        right--;
                    } else if (nums[left] + nums[right] < t2) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
            if (over1) {
                break;
            }
        }

        return ans;
    }
};