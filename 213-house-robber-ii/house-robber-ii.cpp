class Solution {
public:
    int findAns(int n, vector<int>& nums, bool fromLast, vector<int>& dp) {
        if(n < 0) return 0;

        if(fromLast && n == 0) return 0;
        
        if(dp[n] != -1) return dp[n];

        int sum1 = nums[n] + findAns(n-2, nums, fromLast, dp);
        int sum2 = findAns(n-1, nums, fromLast, dp);

        return dp[n] = max(sum1, sum2);
    }
    int rob(vector<int>& nums) {
        // using memoization
        vector<int> dp(nums.size(), -1);
        if(nums.size() == 1) return nums[0];

        bool fromLast = true;
        int sum1 = findAns(nums.size()-1, nums, fromLast, dp);
        fromLast = false;
        for(int i = 0; i < dp.size(); i++) dp[i] = -1;
        int sum2 = findAns(nums.size()-2, nums, fromLast, dp);

        cout << "sum1: " << sum1 << " sum2: " << sum2 << endl;
        return max(sum1, sum2);
    }
};