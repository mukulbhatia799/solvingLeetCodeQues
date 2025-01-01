class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        long long sum = 0;
        int count = 0;
        for(int val: nums) {
            sum += val;

            if(sum == k) count++;

            auto it = mp.find(sum-k);
            if(it != mp.end()) {
                count += it->second;
            }

            mp[sum]++;
        }

        return count;
    }
};