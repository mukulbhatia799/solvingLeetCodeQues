class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        // time complexity:- O(n^3) because one for row, column and innermost loop is for comparision. So, in worst case, it can go upto O(n^3).
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