class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<int> hash(201, -1);
        vector<vector<int>> answer;
        for(int i = 0; i < nums.size(); i++) {
            hash[nums[i]]++;
            if(hash[nums[i]] >= answer.size()) {
                answer.push_back(vector<int>());
            }
            answer[hash[nums[i]]].push_back(nums[i]);
        }
        return answer;
    }
};