class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int ce = 0, co = 0, ceo = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i]%2 == 0) ce++;
            else co++;
        }
        bool prev = (nums[0]&1) ? true:false;
        ceo++;
        for(int i = 1; i < nums.size(); i++) {
            if((nums[i]%2) != prev) {
                ceo++;
                prev = !prev;
            }
        }
        return max(ceo, max(ce, co));

    }
};