#include <bits/stdc++.h> 

bool findAns(int n, int k, vector<int>& arr, vector<vector<int>>& dp) {
    if(k < 0) return false;
    if(k == 0) return true;
    if(n < 0) {
        if(k == 0) return true;
        return false;
    }

    if(dp[n][k] != -1) return dp[n][k];

    bool pick = findAns(n-1, k-arr[n], arr, dp);
    bool notPick = findAns(n-1, k, arr, dp);

    return dp[n][k] = (pick || notPick);
}


bool subsetSumToK(int n, int k, vector<int> &arr) {
    int sum = 0; for(int i = 0; i < arr.size(); i++) sum += arr[i];
    vector<vector<int>> dp(n, vector<int>(sum+1, -1));
    return findAns(n-1, k, arr, dp);
}
