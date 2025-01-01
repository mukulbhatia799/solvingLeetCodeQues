class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pf = 1, sf = 1;
        int maxx = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            pf *= nums[i];
            sf *= nums[nums.size()-i-1];
            maxx = max(maxx, max(pf, sf));
            if(pf == 0) pf = 1;
            if(sf == 0) sf = 1;
        }

        return maxx;
    }
};