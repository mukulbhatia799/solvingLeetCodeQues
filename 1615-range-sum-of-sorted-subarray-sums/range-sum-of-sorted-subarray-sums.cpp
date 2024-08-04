class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long long int> subsum;
        for(int i = 0; i < n; i++) {
            long long int sum = 0;
            for(int j = i; j < n; j++) {
                sum += nums[j];
                subsum.push_back(sum);
            }
        }
        sort(subsum.begin(), subsum.end());
        long long int ans = 0;
        for(int i = left-1; i < right; i++) {
            ans += subsum[i];
        }
        return ans % 1000000007;
    }
};