class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;
        vector<int> result;

        for(int i = 0; i < queries.size(); i++) {
            int ball = queries[i][0];
            int color = queries[i][1];

            if(mp1.find(ball) != mp1.end()) {
                mp2[mp1[ball]]--;

                if(mp2[mp1[ball]] == 0) {
                    mp2.erase(mp1[ball]);
                }
            }

            mp1[ball] = color;
            mp2[color]++;

            result.push_back(mp2.size());
        }

        return result;
    }
};