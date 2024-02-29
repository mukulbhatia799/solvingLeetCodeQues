class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int count = 0;
        for(int j = 0; j < n; j++) {
            for(int i = 0; i < n; i++) {
                if(grid[0][j] == grid[i][0]) {
                    bool check = true;
                    for(int k = 0; k < n; k++) {
                        if(grid[k][j] != grid[i][k]) {
                            check = false; break;
                        }
                    }
                    if(check) count++;
                }
            }
        }
        return count;
    }
};