class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int size = nums.size();
        if(size == 1) return nums[0];
        int ans = 0, curr = 0;

        for(int i = 0; i < size-1; i++) {
            curr += nums[i];
            ans = max(ans, curr);
            if(nums[i] >= nums[i+1]) curr = 0;
        }

        if(nums[size-2] < nums[size-1]) ans = max(ans, curr+nums[size-1]);
        else ans = max(ans, nums[size-1]);

        return ans;
    }
};