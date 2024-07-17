class Solution {
public:
    int findAns(int n, vector<int> &dp) {
        if(n <= 0) return (n==0)?1:0;
        if(dp[n] != -1) return dp[n];
        return dp[n] = findAns(n-1, dp) + findAns(n-2, dp);
    }
    int climbStairs(int n) {
        // using memoization
        vector<int> dp(n+1, -1);
        return findAns(n, dp);
    }
};