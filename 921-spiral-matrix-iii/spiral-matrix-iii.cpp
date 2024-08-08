class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> ans;
        int steps = 1, direction = 0;
        while(ans.size() < rows * cols) {
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < steps; j++) {
                    if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
                        ans.push_back({rStart, cStart});
                    }
                    rStart += dir[direction][0];
                    cStart += dir[direction][1];
                }
                direction = (direction + 1) % 4;
            }
            steps++;
        }
        return ans;
    }
};