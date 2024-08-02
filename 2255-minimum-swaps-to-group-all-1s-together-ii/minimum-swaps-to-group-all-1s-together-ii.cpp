class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int c1 = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i]) c1++;
        }

        int curr = 0;
        for(int i = 0; i < c1; i++) {
            if(nums[i] == 1) curr++;
        }

        int i = 0, j = c1, mini = INT_MAX;
        j = j % nums.size();
        while(i < nums.size()) {
            if(nums[j] == 1) curr++;
            if(nums[i] == 1) curr--;
            i++; j++;
            j = j % nums.size();
            mini = min(mini, c1-curr);
        }
        return mini;

        

    }
};