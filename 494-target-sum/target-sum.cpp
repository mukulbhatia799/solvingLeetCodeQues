class Solution {
public:
    int findAns(int n, vector<int>& nums, int target, int pos, int neg) {
        if(n < 0) {
            return (pos+neg == target);
        }

        // positive value;
        int posSum = findAns(n-1, nums, target, pos+nums[n], neg);

        // negative value;
        int negSum = findAns(n-1, nums, target, pos, neg-nums[n]);

        return (posSum + negSum);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        return findAns(n-1, nums, target, 0, 0);
    }
};