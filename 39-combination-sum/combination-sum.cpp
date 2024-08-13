class Solution {
public:
    void findAns(vector<int>& arr, int target, int ind, vector<int> curr, vector<vector<int>>& ans) {
        if(ind >= arr.size() || target <= 0) {
            if(target == 0) {
                ans.push_back(curr);
            }
            return ;
        }
        curr.push_back(arr[ind]);
        findAns(arr, target-arr[ind], ind, curr, ans);

        curr.pop_back();
        findAns(arr, target, ind+1, curr, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& input, int target) {
        vector<vector<int>> ans;
        
        vector<int> curr;
        sort(input.begin(), input.end());
        findAns(input, target, 0, curr, ans);

        return ans;
    }
};