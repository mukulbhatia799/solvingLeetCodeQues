class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        
        for(int i = 0; i < boxGrid.size(); i++) {
            int space = -1;
            for(int j = boxGrid[i].size()-1; j >= 0; j--) {
                if(boxGrid[i][j] == '.' && space == -1) space = j;
                else if(boxGrid[i][j] == '*') space = -1;
                else if(boxGrid[i][j] == '#' && space != -1) {
                    swap(boxGrid[i][space], boxGrid[i][j]);
                    space--;
                }
            }
        }

        vector<vector<char>> ans(boxGrid[0].size(), vector<char>(boxGrid.size()));

        for(int i = 0; i < ans.size(); i++) {
            for(int j = 0; j < ans[i].size(); j++) {
                ans[i][j] = boxGrid[boxGrid.size()-j-1][i];
            }
        }


        return ans;
    }
};