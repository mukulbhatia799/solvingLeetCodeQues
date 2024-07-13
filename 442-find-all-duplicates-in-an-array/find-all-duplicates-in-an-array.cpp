class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // using hash map
        vector<int> answer;
        map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        for(auto it: mp) {
            if(it.second == 2) answer.push_back(it.first);
        }
        return answer;
    }
};