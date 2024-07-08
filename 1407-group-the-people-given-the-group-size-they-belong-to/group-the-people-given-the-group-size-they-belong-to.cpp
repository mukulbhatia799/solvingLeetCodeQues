class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> answer;
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < groupSizes.size(); i++) {
            mp[groupSizes[i]].push_back(i);
            if(mp[groupSizes[i]].size() == groupSizes[i]) {
                answer.push_back(mp[groupSizes[i]]);
                mp.erase(groupSizes[i]);
            }
        }
        for(auto it: mp) {
            answer.push_back(it.second);
        }
        return answer;
    }
};