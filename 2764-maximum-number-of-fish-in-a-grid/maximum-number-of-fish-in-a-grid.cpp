class Solution {
public:
    int dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == 0)
            return 0;
        
        int fish = grid[r][c];
        grid[r][c] = 0;
        
        fish += dfs(grid, r + 1, c);
        fish += dfs(grid, r - 1, c);
        fish += dfs(grid, r, c + 1);
        fish += dfs(grid, r, c - 1);
        
        return fish;
    }
    
    int findMaxFish(vector<vector<int>>& grid) {
        int maxFish = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] > 0) {
                    maxFish = max(maxFish, dfs(grid, i, j));
                }
            }
        }
        return maxFish;
    }
};