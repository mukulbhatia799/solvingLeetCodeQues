const int mod = 1e9+7;
int findAns(int n, int k, vector<int>& arr, vector<vector<int>>& dp) {
    if(k < 0) return 0;
    if(n < 0) return k ? 0:1;

    if(dp[n][k] != -1) return dp[n][k];

    int pick = findAns(n-1, k-arr[n], arr, dp);
    int notPick = findAns(n-1, k, arr, dp);

    return dp[n][k] = (pick+notPick)%mod;
}


int findWays(vector<int>& arr, int k)
{
	// using memoization
    vector<vector<int>> dp(arr.size(), vector<int>(k+1, -1));
    return findAns(arr.size()-1, k, arr, dp);
}
