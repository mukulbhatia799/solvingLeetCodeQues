#include <bits/stdc++.h> 
const int mod = 1e9+7;

int findAns(int n, int d, vector<int>& arr, int sum1, int sum2, int actualSum, vector<vector<int>>& dp) {
    if(n < 0) {
        if(sum1-sum2 == d) return 1;
        return 0;
    }

    int diff = (sum1-sum2) < 0 ? abs(sum1-sum2) : actualSum+abs(sum1-sum2);
    if(dp[n][diff] != -1) return dp[n][diff];

    int to1 = findAns(n-1, d, arr, sum1+arr[n], sum2, actualSum, dp);
    int to2 = findAns(n-1, d, arr, sum1, sum2+arr[n], actualSum, dp);

    return dp[n][diff] = (to1+to2)%mod;
}


int countPartitions(int n, int d, vector<int> &arr) {
    // using memoization
    int sum = 0; for(int i = 0; i < arr.size(); i++) sum += arr[i];
    vector<vector<int>> dp(n, vector<int>(2*(sum+1), -1));
    return findAns(n-1, d, arr, 0, 0, sum, dp);
}


