class Solution {
public:
    unordered_map<int, int> cache;
    // 递归+cache
    int climbStairs1(int n) {
        if (n <= 2) {
            return n;
        }
        if (cache.find(n) != cache.end()) {
            return cache[n];
        }
        int ret = climbStairs(n - 1) + climbStairs(n - 2);
        cache[n] = ret;
        return ret;
    }
    // dp
    int climbStairs(int n) {
        if (n <= 1) return 1;
        vector<int> f(n + 1);
        f[0] = 1, f[1] = 1;
        for (int i = 2; i <= n; i++) {
            f[i] = f[i - 1] + f[i - 2];
        }
        return f[n];
    }
};
