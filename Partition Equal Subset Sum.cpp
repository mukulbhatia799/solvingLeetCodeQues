
bool findAns(int n, vector<int>& arr, int sum1, int sum2, vector<vector<int>>& dp) {
	if(n < 0) {
		if(sum1 == sum2) return true;
		else return false;
	}

	if(dp[n][abs(sum1-sum2)] != -1) return dp[n][abs(sum1-sum2)];

	bool to1 = findAns(n-1, arr, sum1+arr[n], sum2, dp);
	bool to2 = findAns(n-1, arr, sum1, sum2+arr[n], dp);

	return dp[n][abs(sum1-sum2)] = (to1 || to2);
}

bool canPartition(vector<int> &arr, int n)
{
	int sum = 0; for(int i = 0; i < n; i++) sum += arr[i];
	vector<vector<int>> dp(n, vector<int>(sum+1, -1));
	return findAns(n-1, arr, 0, 0, dp);
}
