class Solution {
public:
    int findAns(int n, vector<int>& dp) {
        if(n < 0) return 0;
        if(n == 0) return 1;

        if(dp[n] != -1) return dp[n];

        int step1 = findAns(n-1, dp);
        int step2 = findAns(n-2, dp);

        return dp[n] = step1+step2;
    }
    int climbStairs(int n) {
        // using memoization.
        vector<int> dp(n+1, -1);
        return findAns(n, dp);
    }
};