class Solution {
public:
    double pow(double x, long n) {
        if (n == 0) {
            return 1;
        } else if (n == 1) {
            return x;
        }
        double ret = pow(x, n/2);
        if (n % 2 == 1) {
            return ret * ret * x;
        } else {
            return ret * ret;
        }
    }
    double myPow2(double x, int n) {
        return n >= 0 ? pow(x, n) : pow(1/x, -(long)n);
    }

    double myPow(double x, int n) {
        long m = (long)n;
        if (n < 0) {
            x = 1 / x;
            m = -(long)n;
        }
        double ret = 1.0;
        while (m > 0) {
            if (m % 2 == 1) {
                ret *= x; 
            }
            x *= x;
            m /= 2;
        }
        return ret;
    }
};