class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for(int i = 0; i < nums.size(); i++) {

            if(i != 0 && nums[i] == nums[i-1]) continue;

            for(int j = i+1; j < nums.size(); j++) {

                if(j != i+1 && nums[j] == nums[j-1]) continue;

                int k = j+1, m = nums.size()-1;

                while(k < m) {
                    long long int sum = nums[i] + nums[j];
                    sum += nums[k] + nums[m];
                    
                    if(sum == target) {
                        ans.push_back({nums[i], nums[j], nums[k], nums[m]});

                        k++; m--;
                        while(k < m && nums[k] == nums[k-1]) k++;
                        while(k < m && nums[m] == nums[m+1]) m--;
                    }
                    else if(sum > target) m--;
                    else k++;
                }
            }
        }

        return ans;
    }
};