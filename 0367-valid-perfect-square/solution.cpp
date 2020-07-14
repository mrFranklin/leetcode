class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1;
        int right = num;
        long mul;
        int mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            mul = (long)mid * mid;
            if (mul == (long)num) {
                return true;
            } else if (mul < (long)num) {
                left = mid + 1;           
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};