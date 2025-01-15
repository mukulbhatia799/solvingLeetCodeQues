class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> col1(m, 0), row1(n, 0);

        for(int i = 0; i < n; i++) {
            int t_row = 0;
            for(int j = 0; j < m; j++) {
                t_row += grid[i][j];
                col1[j] += grid[i][j];
            }
            row1[i] = t_row;
        }

        vector<vector<int>> ans(n, vector<int>(m,0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans[i][j] = row1[i] + col1[j] - (m-row1[i]) - (n-col1[j]);
            }
        }

        return ans;
    }
};