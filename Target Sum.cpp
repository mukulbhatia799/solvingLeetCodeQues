#include <bits/stdc++.h> 

int findAns(int n, int target, vector<int>& arr, int add, int sub, int totalSum, vector<vector<int>>& dp) {
    if(n < 0) {
        if(add-sub == target) return 1;
        return 0;
    }

    int diff = add-sub <= 0 ? abs(add-sub) : totalSum+abs(add-sub);

    if(dp[n][diff] != -1) return dp[n][diff];

    int toAdd = findAns(n-1, target, arr, add+arr[n], sub, totalSum, dp);
    int toSub = findAns(n-1, target, arr, add, sub+arr[n], totalSum, dp);

    return dp[n][diff] = toAdd+toSub;
}

int targetSum(int n, int target, vector<int>& arr) {
    int sum = 0; for(int i = 0; i < n; i++) sum += arr[i];
    vector<vector<int>> dp(n, vector<int>(2*(sum+1), -1));
    return findAns(n-1, target, arr, 0, 0, sum, dp);
}
