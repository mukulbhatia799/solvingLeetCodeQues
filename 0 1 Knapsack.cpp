#include <bits/stdc++.h> 

int findAns(vector<int>& weight, vector<int>& value, int n, int w, vector<vector<int>>& dp) {
	if(n < 0) return 0;

	if(dp[n][w] != -1) return dp[n][w];

	int pick = 0;
	if(w-weight[n] >= 0) pick =  value[n] + findAns(weight, value, n-1, w-weight[n], dp);
	int notPick = findAns(weight, value, n-1, w, dp);

	return dp[n][w] = max(pick, notPick);
}


int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// using memoization
	vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));
	return findAns(weight, value, n-1, maxWeight, dp);
}
