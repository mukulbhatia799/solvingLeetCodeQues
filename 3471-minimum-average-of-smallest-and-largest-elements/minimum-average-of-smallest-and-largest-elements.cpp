class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size()-1;
        double mini = INT_MAX;
        while(i < j) {
            double value = double(nums[i++]+nums[j--])/2;
            cout << value << " ";
            mini = min(mini, value);
        }
        return mini;
    }
};