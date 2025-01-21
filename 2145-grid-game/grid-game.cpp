class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long temp1 = 0, temp2 = 0;

        for (int num : grid[0]) temp1 += num;

        long long ans = LLONG_MAX;

        for (int i = 0; i < grid[0].size(); ++i) {
            temp1 -= grid[0][i];
            ans = min(ans, max(temp1, temp2));
            temp2 += grid[1][i];
        }

        return ans;
    }
};