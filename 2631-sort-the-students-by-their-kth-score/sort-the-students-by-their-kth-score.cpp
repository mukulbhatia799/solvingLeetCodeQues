class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        vector<pair<int, int>> vpr;
        for(int i = 0; i < score.size(); i++) {
            vpr.push_back({score[i][k], i});
        }

        sort(vpr.begin(), vpr.end(), greater<pair<int, int>>());
        vector<vector<int>> ans(score.size(), vector<int>(score[0].size(), 0));
        for(int ind = 0; ind < score.size(); ind++) {
            int i = vpr[ind].second;
            for(int j = 0; j < score[i].size(); j++) {
                ans[ind][j] = score[i][j];
            }
        }

        return ans;

    }
};