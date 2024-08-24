#include <bits/stdc++.h> 

int findAns(int m, int n, vector<vector<int>>& dp) {
    if(m == 0 && n == 0) return 1;

    if(dp[m][n] != -1) return dp[m][n];

    int sum = 0;
    if(m-1 >= 0) sum += findAns(m-1, n, dp);
    if(n-1 >= 0) sum += findAns(m, n-1, dp);

    return dp[m][n] = sum;
}

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));
	return findAns(m-1, n-1, dp);
}
