class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<bool> dp(n+1, true);
        dp[0] = false;
        int j = 1;
        for(int i = 0; i < n-1; i++) {
            int curr = k;
            while(curr) {
                if(dp[j%(n+1)] == true) curr--;
                j++;
            }
            dp[(j-1)%(n+1)] = false;
        }
        for(int i = 1; i <= n; i++) {
            if(dp[i] == true) return i;
        }
        return -1;
    }
};