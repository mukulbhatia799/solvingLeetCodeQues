class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++) {
            
            if(i != 0 && nums[i] == nums[i-1]) continue;

            int j = i+1, k = nums.size()-1;

            while(j < k) {
                int sum = nums[i]+nums[j]+nums[k];
                
                if(sum == 0) {
                    vector<int> vec = {nums[i], nums[j], nums[k]};
                    sort(vec.begin(), vec.end());
                    ans.push_back(vec);
                    j++; k--;
                    while(j < k && nums[k] == nums[k+1]) k--;
                    while(j < k && nums[j] == nums[j-1]) j++;
                }
                else if(sum > 0) {
                    k--;
                }
                else {
                    j++;
                }
            }
        }

        return ans;
    }
};