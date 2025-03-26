class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        for(int i = n-1; i > 0; i--) {
            if(nums[i] > nums[i-1]) {
                sort(nums.begin()+i, nums.end());
                for(int j = i; j < n; j++) {
                    if(nums[i-1] < nums[j]) {
                        swap(nums[i-1], nums[j]);
                        return;
                    }
                }
            }
        }

        sort(nums.begin(), nums.end());
    }
};