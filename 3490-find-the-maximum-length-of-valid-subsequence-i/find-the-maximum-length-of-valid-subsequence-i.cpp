class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int ce = 0, co = 0, ceo = 1;
        bool prev = (nums[0]&1) ? true:false;
        if(nums[0]&1) co++; else ce++;
        for(int i = 1; i < n; i++) {
            if(nums[i]&1) co++;
            else ce++;
            if((nums[i]&1) != prev) {
                ceo++;
                prev = !prev;
            }
        }

        return max(ceo, max(ce, co));

    }
};