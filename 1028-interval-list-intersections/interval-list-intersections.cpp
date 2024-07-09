class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& fl, vector<vector<int>>& sl) {
        int n = fl.size(), m = sl.size();
        vector<vector<int>> answer;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if((fl[i][0] >= sl[j][0] && fl[i][1] <= sl[j][1]) || (sl[j][0] >= fl[i][0] && sl[j][1] <= fl[i][1])) {
                    answer.push_back({max(fl[i][0], sl[j][0]), min(fl[i][1], sl[j][1])});
                }
                else if((fl[i][0] >= sl[j][0] && fl[i][0] <= sl[j][1]) || (sl[j][0] >= fl[i][0] && sl[j][0] <= fl[i][1])) {
                    answer.push_back({max(fl[i][0], sl[j][0]), min(fl[i][1], sl[j][1])});
                }
            }
        }
        return answer;
    }
};