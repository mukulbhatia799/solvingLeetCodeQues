class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> smaller, larger, equal, answer;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < pivot) smaller.push_back(nums[i]);
            else if(nums[i] > pivot) larger.push_back(nums[i]);
            else equal.push_back(nums[i]);
        }
        for(int val: smaller) answer.push_back(val);
        for(int val: equal) answer.push_back(val);
        for(int val: larger) answer.push_back(val);

        return answer;
    }
};