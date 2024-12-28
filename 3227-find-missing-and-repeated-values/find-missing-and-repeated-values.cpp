class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int, int> mp;

        int dup = -1, currSum = 0;
        for(auto vec: grid) {
            for(int val: vec) {
                if(mp.find(val) != mp.end()) {
                    dup = val;
                }
                currSum += val;
                mp[val]++;
            }
        }
        int n = grid.size()*grid.size();
        int miss = n*(n+1)/2 - (currSum - dup);
        return {dup, miss};
    }
};