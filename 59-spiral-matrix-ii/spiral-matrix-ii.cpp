class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int l = 0, r = n-1, t = 0, d = n-1, curr = 1;
        while(l <= r && t <= d) {
            for(int i = l; i <= r; i++) {
                ans[t][i] = curr++;
            }
            t++;
            for(int i = t; i <= d; i++) {
                ans[i][r] = curr++;
            }
            r--;
            if(t <= d)
            for(int i = r; i >= l; i--) {
                ans[d][i] = curr++;
            }
            d--;
            if(l <= r)
            for(int i = d; i >= t; i--) {
                ans[i][l] = curr++;
            }
            l++;
        }
        return ans;
    }
};