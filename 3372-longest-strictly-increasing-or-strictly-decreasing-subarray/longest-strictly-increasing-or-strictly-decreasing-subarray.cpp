class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1;

        for(int i = 0; i < nums.size()-1; i++) {
            int count = 1;
            while(i < nums.size()-1 && nums[i] > nums[i+1]) {
                count++; i++;
            }
            ans = max(ans, count);
        }

        for(int i = 0; i < nums.size(); i++) {
            int count = 1;
            while(i < nums.size()-1 && nums[i] < nums[i+1]) {
                count++; i++;
            }
            ans = max(ans, count);
        }

        return ans;
    }
};