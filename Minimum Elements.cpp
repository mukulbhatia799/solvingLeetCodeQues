#include <bits/stdc++.h> 

int findAns(int n, int x, vector<int>& nums, int cnt, vector<vector<int>>& dp) {
    if(n < 0 || x == 0) {
        if(x == 0) return cnt;
        return INT_MAX;
    }

    if(dp[n][x] != -1) return dp[n][x];

    int take = INT_MAX;
    if(x-nums[n] >= 0) take = findAns(n, x-nums[n], nums, cnt+1, dp);
    int notTake = findAns(n-1, x, nums, cnt, dp);

    return dp[n][x] = min(take, notTake);
}


int minimumElements(vector<int> &nums, int x)
{
    // using memoization
    vector<vector<int>> dp(nums.size(), vector<int>(x+1, -1));
    sort(nums.begin(), nums.end());

    int ans = findAns(nums.size()-1, x, nums, 0, dp);
    if(ans == INT_MAX) return -1;
    return ans;
}
