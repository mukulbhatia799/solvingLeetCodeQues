class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        vector<int> row(mat.size(), mat[0].size()), col(mat[0].size(), mat.size());
        
        unordered_map<int, pair<int, int> > mp; // <value, index>

        for(int i = 0; i < mat.size(); i++) {
            for(int j = 0; j < mat[i].size(); j++) {
                mp[mat[i][j]] = {i, j};
            }
        }
        
        for(int i = 0; i < arr.size(); i++) {
            pair<int, int> pr = mp[arr[i]];
            row[pr.first]--;
            col[pr.second]--;
            if(row[pr.first] == 0 || col[pr.second] == 0) return i;
        }

        return -1;
    }
};