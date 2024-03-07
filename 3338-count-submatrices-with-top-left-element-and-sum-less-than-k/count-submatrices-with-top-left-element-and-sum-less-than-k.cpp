class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, long long int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<long long int>> vec(n, vector<long long int>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                vec[i][j] = grid[i][j];
            }
        }
        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i > 0 && j > 0) {
                    vec[i][j] = vec[i-1][j] + vec[i][j-1] - vec[i-1][j-1] + vec[i][j];
                }
                else if(i > 0) {
                    vec[i][j] = vec[i-1][j] + vec[i][j];
                }
                else if(j > 0) {
                    vec[i][j] = vec[i][j-1] + vec[i][j];
                }
                else {
                    vec[i][j] = vec[i][j];
                }
                if(vec[i][j] > k) {
                    vec[i][j] = INT_MAX; break;
                }
                if(vec[i][j] <= k) {
                    count++;
                }
            }
        }
                
        return count;
        
    }
};