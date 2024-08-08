class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        int l = 0, t = 0, r = n-1, d = m-1;
        while(l <= r && t <= d) {
            for(int i = l; i <= r; i++) {
                ans.push_back(matrix[t][i]);
            }
            t++;
            for(int i = t; i <= d; i++) {
                ans.push_back(matrix[i][r]);
            }
            r--;
            if(t <= d)
            for(int i = r; i >= l; i--) {
                ans.push_back(matrix[d][i]);
            }
            d--;
            if(l <= r)
            for(int i = d; i >= t; i--) {
                ans.push_back(matrix[i][l]);
            }
            l++;
            cout << "l: " << l << " r: " << r << " t: " << t << " d: " << d << endl;
        }
        return ans;
    }
};