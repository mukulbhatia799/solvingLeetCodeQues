class Solution {
public:
    int findAns(int n, vector<int>& nums, int target, int pos, int neg, int sum, vector<vector<int>> &dp) {
        if(n < 0) {
            return (pos+neg == target);
        }

        int col = (pos+neg <= 0) ? abs(pos+neg) : sum+abs(pos+neg);
        if(dp[n][col] != -1) return dp[n][col];

        // positive value;
        int posSum = findAns(n-1, nums, target, pos+nums[n], neg, sum, dp);

        // negative value;
        int negSum = findAns(n-1, nums, target, pos, neg-nums[n], sum, dp);

        return dp[n][col] = (posSum + negSum);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        // using memoization
        int n = nums.size();

        int sum = 0;
        for(int i = 0; i < n; i++) sum += nums[i];

        vector<vector<int>> dp(n, vector<int> ((sum+1)*2, -1));

        return findAns(n-1, nums, target, 0, 0, sum, dp);
    }
};