class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if (nums.size() == 0) {
            return vector<int>();
        }
        int n = 2;
        vector<int> cand;
        vector<int> count;
        cand.assign(2, nums[0]);
        count.assign(2, 0);

        for (int i = 0; i < nums.size(); i++) {
            bool findOne = false;
            for (int j = 0; j < cand.size(); j++) {
                if (cand[j] == nums[i]) {
                    count[j]++;
                    findOne = true;
                    break;
                }
            }
            if (findOne) {
                continue;
            }

            findOne = false;
            for (int j = 0; j < cand.size(); j++) {
                if (count[j] == 0) {
                    cand[j] = nums[i];
                    count[j]++;
                    findOne = true;
                    break;
                }
            }
            if (findOne) {
                continue;
            }
            
            for (int j = 0; j < cand.size(); j++) {
                count[j]--;
            }
        }

        vector<int> ret;
        for (int i = 0; i < cand.size(); i++) {
            if (count[i] <= 0) {
                continue;
            }
            int count = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] == cand[i]) {
                    count++;
                }
            }
            if (count > nums.size() / 3) {
                ret.push_back(cand[i]);
            }
        }

        return ret;
    }
};