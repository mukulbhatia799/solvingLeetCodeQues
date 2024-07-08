class Solution {
public: 
    int findAns(int n, vector<int>& dp) {
        if(n <= 0) return 0;
        if(n == 1 || n == 2) return 1;
        if(dp[n] != -1) return dp[n];
        return dp[n] = findAns(n-1, dp) + findAns(n-2, dp) + findAns(n-3, dp);
    }
    int tribonacci(int n) {
        // using memoization
        vector<int> dp(n+1, -1);
        return findAns(n, dp);
    }
};