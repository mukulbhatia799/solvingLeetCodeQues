
const int mod = 1e9+7;
int findAns(int n, int m, vector<vector<int>>& mat, vector<vector<int>>& dp) {
    if(n == 0 && m == 0) return 1;

    if(mat[n][m] == -1) return 0;

    if(dp[n][m] != -1) return dp[n][m];
    long long int sum = 0;
    if(n-1 >= 0) sum += findAns(n-1, m, mat, dp);
    if(m-1 >= 0) sum += findAns(n, m-1, mat, dp);

    return dp[n][m] = sum%mod;
}


int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // using memoization
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return findAns(n-1, m-1, mat, dp);
}
