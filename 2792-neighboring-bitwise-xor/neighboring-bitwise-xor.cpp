class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int ans = 0;
        for(int val : derived) ans ^= val;
        
        return ans == 0;
    }
};