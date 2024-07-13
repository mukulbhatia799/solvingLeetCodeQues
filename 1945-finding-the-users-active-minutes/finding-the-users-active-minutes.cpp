class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        map<int, set<int>> mp;
    
        for(int i = 0; i < logs.size(); i++) mp[logs[i][0]].insert(logs[i][1]);
        
        vector<int> answer(k, 0);
        for(auto it: mp) answer[it.second.size()-1]++;
        return answer;
    }
};