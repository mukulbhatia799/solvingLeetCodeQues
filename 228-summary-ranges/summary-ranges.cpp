class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.size() == 0) return ans;
        int start = nums[0], end = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i]-1 == nums[i-1]) {
                end = nums[i];
            }
            else if(start != end) {
                string str = to_string(start)+"->"+to_string(end);
                ans.push_back(str);
                start = nums[i];
                end = nums[i];
            }
            else {
                ans.push_back(to_string(start));
                start = nums[i];
                end = nums[i];
            }
        }

        if(start != end) {
            string str = to_string(start)+"->"+to_string(end);
            ans.push_back(str);
        }
        else {
            ans.push_back(to_string(start));
        }

        return ans;
    }
};