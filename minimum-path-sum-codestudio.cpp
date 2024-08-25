#include <bits/stdc++.h>


int findAns(int n, int m, vector<vector<int>>& grid, vector<vector<int>>& dp) {
    if(n == 0 && m == 0) return grid[n][m];

    if(dp[n][m] != -1) return dp[n][m];
    int sum1 = 0, sum2 = 0;
    if(n-1 < 0) sum1 = 1e9;
    else sum1 += findAns(n-1, m, grid, dp);
    if(m-1 < 0) sum2 = 1e9;
    else sum2 += findAns(n, m-1, grid, dp);

    return dp[n][m] = min(sum1+grid[n][m], sum2+grid[n][m]);
}


int minSumPath(vector<vector<int>> &grid) {
    // using memoization
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return findAns(n-1, m-1, grid, dp);
}
