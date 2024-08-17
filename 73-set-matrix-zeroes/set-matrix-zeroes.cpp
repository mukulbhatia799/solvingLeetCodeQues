class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> row, col;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                if(matrix[i][j] == 0) {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for(int ind: row) {
            for(int i = 0; i < matrix[ind].size(); i++) {
                matrix[ind][i] = 0;
            }
        }
        for(int ind: col) {
            for(int i = 0; i < matrix.size(); i++) {
                matrix[i][ind] = 0;
            }
        }
    }
};