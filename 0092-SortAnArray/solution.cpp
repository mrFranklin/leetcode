class Solution {
public:
    vector<int> bubbleSort1(vector<int>& nums) {
        for (int i = nums.size() - 1; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                if (nums[j] > nums[j+1]) {
                    swap(nums[j], nums[j+1]);
                }
            }
        }
        return nums;
    }
    vector<int> bubbleSort(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < nums.size() - i; j++) {
                if (nums[j] > nums[j+1]) {
                    swap(nums[j], nums[j+1]);
                }
            }
        }
        return nums;
    }

    vector<int> insertSort(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            int num = nums[i];
            int j = i - 1;
            for (; j >= 0; j--) {
                if (num < nums[j]) {
                    nums[j+1] = nums[j];
                } else {
                    break;
                }
            }
            nums[j+1] = num;
        }
        return nums;
    }

    vector<int> selectSort(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            int min = i;
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] < nums[min]) {
                    min = j;
                }
            }
            swap(nums[i], nums[min]);
        }
        return nums;
    }

    int partition(vector<int>& nums, int start, int end) {
        int index = start;
        int pivot = end;
        for (int i = start; i <= end; i++) {
            if (nums[i] < nums[pivot]) {
                swap(nums[i], nums[index]);
                index++;    
            }
        }
        swap(nums[index], nums[pivot]);
        return index;
    }

    void qsort(vector<int>& nums, int start, int end) {
        if (start >= end) {
            return;
        }
        int pivot = partition(nums, start, end);
        qsort(nums, start, pivot-1);
        qsort(nums, pivot+1, end);
    }

    vector<int> quickSort(vector<int>& nums) {
        qsort(nums, 0, nums.size()-1);
        return nums;
    }

    void merge(vector<int>& nums, int start, int mid, int end) {
        vector<int> ret;
        int i = start, j = mid+1;
        while (i <= mid && j <= end) {
            if (nums[i] < nums[j]) {
                ret.push_back(nums[i]);
                i++;
            } else {
                ret.push_back(nums[j]);
                j++;
            }
        }
        while (i <= mid) {
            ret.push_back(nums[i]);
            i++;
        }
        while (j <= end) {
            ret.push_back(nums[j]);
            j++;
        }
        for (i = start; i <= end; i++) {
            nums[i] = ret[i - start];
        }
    }
    void msort(vector<int>& nums, int start, int end) {
        if (start >= end) {
            return;
        }
        int mid = (start + end) / 2;
        msort(nums, start, mid);
        msort(nums, mid+1, end);
        merge(nums, start, mid, end);
    }
    vector<int> mergeSort(vector<int>& nums) {
        msort(nums, 0, nums.size()-1);
        return nums;
    }

    vector<int> sortArray(vector<int>& nums) {
        // return bubbleSort(nums);
        // return insertSort(nums);
        // return selectSort(nums);
        return quickSort(nums);
        // return mergeSort(nums);
    }
};