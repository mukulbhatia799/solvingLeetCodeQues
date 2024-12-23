class Solution {
public:
    int thirdMax(vector<int>& nums) {
        map<int, int, greater<int>> mp;

        int maxi = INT_MIN;
        for(auto val: nums) {
            mp[val]++;
            maxi = max(maxi, val);
        }
        
        int ptr = 3;
        for(auto it: mp) {
            ptr--;
            if(ptr == 0) return it.first;
        }

        return maxi;
    }
};