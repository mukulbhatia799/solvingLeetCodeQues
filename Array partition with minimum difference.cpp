

int findAns(int n, vector<int>& arr, int sum1, int sum2, vector<vector<int>>& dp) {
	if(n < 0) {
		return abs(sum1-sum2);
	}

	if(dp[n][abs(sum1-sum2)] != -1) return dp[n][abs(sum1-sum2)];

	int to1 = findAns(n-1, arr, sum1+arr[n], sum2, dp);
	int to2 = findAns(n-1, arr, sum1, sum2+arr[n], dp);

	return dp[n][abs(sum1-sum2)] = min(to1, to2);
}


int minSubsetSumDifference(vector<int>& arr, int n)
{
	// using memoization
	int sum = 0; for(int i = 0; i < n; i++) sum += arr[i];
	vector<vector<int>> dp(n, vector<int>(sum+1, -1));
	return findAns(n-1, arr, 0, 0, dp);
}
