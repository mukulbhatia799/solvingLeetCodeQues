class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1, arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        for(int i = 2; i < nums.size(); i++) {
            if(arr1[arr1.size()-1] > arr2[arr2.size()-1]) {
                arr1.push_back(nums[i]);
            }
            else arr2.push_back(nums[i]);
        }
        vector<int> answer = arr1;
        for(int val: arr2) {
            answer.push_back(val);
        }
        
        return answer;
    }
};