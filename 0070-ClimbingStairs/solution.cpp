class Solution {
public:
    unordered_map<int, int> cache;
    int climbStairs(int n) {
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
};