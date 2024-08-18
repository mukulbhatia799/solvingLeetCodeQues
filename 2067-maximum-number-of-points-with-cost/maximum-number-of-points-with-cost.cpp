#define ll long long
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m=points.size(), n=points[0].size();

        vector<ll> prevRow(n);
        for(int j=0; j<n; j++){
            prevRow[j] = points[0][j];
        }

        for(int i=1; i<m; i++){
            vector<ll> leftMax(n), rightMax(n), currRow(n);

            leftMax[0] = prevRow[0];
            for(int j=1; j<n; j++){ // if our previous column was j, then which column will yield us maxscore, if we see left of j'th colm
                leftMax[j] = max(leftMax[j-1]-1, prevRow[j]);
            }

            rightMax[n-1] = prevRow[n-1];
            for(int j=n-2; j>=0; j--){ // if our previous column was j, then which column will yield us maxscore, if we see right of j'th colm
                rightMax[j] = max(rightMax[j+1]-1, prevRow[j]);
            }

            for(int j=0; j<n; j++){ // now if we take j'th element in current row, then we can directly know what will be our maxScore, for every column
                currRow[j] = points[i][j] + max(leftMax[j], rightMax[j]);
            }

            prevRow = currRow;
        }

        ll score = 0;
        for(int j=0; j<n; j++){
            score = max(score, prevRow[j]);
        }
        return score;
    }
};