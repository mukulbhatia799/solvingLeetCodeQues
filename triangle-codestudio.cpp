#include <bits/stdc++.h> 

int findAns(int x, vector<vector<int>>& triangle, int y, vector<vector<int>>& dp) {
	if(x == triangle.size()-1) return triangle[x][y];

	if(dp[x][y] != -1) return dp[x][y];

	int solve1 = findAns(x+1, triangle, y, dp) + triangle[x][y];
	int solve2 = findAns(x+1, triangle, y+1, dp) + triangle[x][y];

	return dp[x][y] = min(solve1, solve2);
}

int minimumPathSum(vector<vector<int>>& triangle, int n){
	// using memoization
	vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), -1));
	return findAns(0, triangle, 0, dp);
}
